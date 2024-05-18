/*
Copyright 2024 Tomoaki Itoh
This software is released under the MIT License, see LICENSE.txt.
//*/

#include "unit_delfx.h"
#include <climits>
#include "utils/buffer_ops.h"
#include "LCWDelay.h"
#include "LCWDelayParam.h"

#define param_10bit_to_8bit(val) (val >> 2) // 0..0x3FF -> 0..0xFF
#define param_10bit_to_6bit(val) (val >> 4) // 0..0x3FF -> 0..0x3F

enum {
    TIME = 0U,
    DEPTH,
    MIX,
    TYPE,
    NUM_PARAMS
};

static struct {
    int32_t time = 0;
    int32_t depth = 0;
    float mix = 0.f;
    int32_t filterIndex = 0;
} s_param;

static unit_runtime_desc_t runtime_desc;
static float *delay_ram_sampling;
static float *delay_ram_input;

static LCWDelayBuffer delayLine;
static LCWDelayBuffer inputBuffer;
static LCWDelayBlock delayBlock;

// ---- Callbacks exposed to runtime ----------------------------------------------

__unit_callback int8_t unit_init(const unit_runtime_desc_t * desc) {
    if (!desc)
        return k_unit_err_undef;

    if (desc->target != unit_header.target)
        return k_unit_err_target;

    if (!UNIT_API_IS_COMPAT(desc->api))
        return k_unit_err_api_version;

    if (desc->samplerate != 48000)
        return k_unit_err_samplerate;

    if (desc->input_channels != 2 || desc->output_channels != 2)
        return k_unit_err_geometry;

    if (!desc->hooks.sdram_alloc)
        return k_unit_err_memory;

    delay_ram_sampling = (float *)desc->hooks.sdram_alloc(LCW_DELAY_SAMPLING_SIZE * sizeof(float));
    if (!delay_ram_sampling)
        return k_unit_err_memory;

    delay_ram_input = (float *)desc->hooks.sdram_alloc(LCW_DELAY_IO_BUFFER_SIZE * sizeof(float));
    if (!delay_ram_input)
        return k_unit_err_memory;

    runtime_desc = *desc;

    // set default values
    s_param.time = 0;
    s_param.depth = 0;
    s_param.mix = 0.f;
    s_param.filterIndex = 0;

    delayLine.buffer = delay_ram_sampling;
    delayLine.size = LCW_DELAY_SAMPLING_SIZE;
    delayLine.mask = LCW_DELAY_SAMPLING_SIZE - 1;
    delayLine.pointer = 0;

    inputBuffer.buffer = delay_ram_input;
    inputBuffer.size = LCW_DELAY_IO_BUFFER_SIZE;
    inputBuffer.mask = LCW_DELAY_IO_BUFFER_SIZE - 1;
    inputBuffer.pointer = 0;

    delayBlock.delayLine = &delayLine;
    delayBlock.inputBuffer = &inputBuffer;
    delayBlock.param.fbGain = 0.f;
    delayBlock.param.position = 0.f;
    delayBlock.currentPosition = 0.f;

    LCWDelayInit(&delayBlock);

    return k_unit_err_none;
}

__unit_callback void unit_teardown() {
    delay_ram_sampling = nullptr;
    delay_ram_input = nullptr;
}

__unit_callback void unit_reset() {
}

__unit_callback void unit_resume() {
}

__unit_callback void unit_suspend() {
}

#define LCW_FILTER_TYPE_MAX (LCW_DELAY_NUMBER_OF_FILTER_TYPE - 1)
__unit_callback void unit_render(const float * in, float * out, uint32_t frames) {
    const int32_t delayTime = param_10bit_to_8bit(s_param.time);
    delayBlock.param.position = (float)delayTimeParams[delayTime];

    const int32_t depthIndex = param_10bit_to_6bit(s_param.depth);
    delayBlock.param.fbGain = -1 * delayFbGainTable[depthIndex]; // memo: 符号反転はお好み

    delayBlock.param.filterIndex =
        clipminmaxi32(0, s_param.filterIndex, LCW_FILTER_TYPE_MAX);
    LCWDelayUpdate(&delayBlock);

    const float * __restrict in_p = in;
    float * __restrict out_p = out;
    const float * out_e = out_p + (frames << 1); // output_channels: 2

    // -1.0 .. +1.0 -> 0.0 .. 1.0
    const float wet = (s_param.mix + 1.f) / 2.f;
    const float dry = 1.f - wet;

    for (; out_p != out_e; in_p += 2, out_p += 2) {
        const float xL = *(in_p + 0);
        // const float xR = *(in_p + 1);

        const float wL = LCWDelayProcess(&delayBlock, xL);
        // const float wR = xR;

        out_p[0] =
        out_p[1] = (dry * xL) + (wet * wL);
        // *(x++) = (dry * xR) + (wet * wR);
    }
}

__unit_callback void unit_set_param_value(uint8_t id, int32_t value) {
    switch (id) {
    case TIME:
        value = clipminmaxi32(0, value, 1023);
        s_param.time = value;
        break;
    case DEPTH:
        value = clipminmaxi32(0, value, 1023);
        s_param.depth = value;
        break;
    case MIX:
        // -1000 .. 1000 -> -1.0 .. 1.0
        value = clipminmaxi32(-1000, value, 1000);
        s_param.mix = value / 1000.f;
        break;
    case TYPE:
        s_param.filterIndex = value;
        break;
    default:
        break;
    }
}

__unit_callback int32_t unit_get_param_value(uint8_t id) {
    switch (id) {
    case TIME:
        return s_param.time;
        break;
    case DEPTH:
        return s_param.depth;
        break;
    case MIX:
        // -1.0 .. 1.0 -> -1000 .. 1000
        return (int32_t)(s_param.mix * 1000);
        break;
    case TYPE:
        return s_param.filterIndex;
        break;
    default:
        break;
    }

    return INT_MIN;
}

__unit_callback const char * unit_get_param_str_value(uint8_t id, int32_t value) {
    return nullptr;
}

__unit_callback void unit_set_tempo(uint32_t tempo) {
}

__unit_callback void unit_tempo_4ppqn_tick(uint32_t counter) {
}
