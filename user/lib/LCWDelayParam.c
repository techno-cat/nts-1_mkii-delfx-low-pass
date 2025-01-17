/*
Copyright 2024 Tomoaki Itoh
This software is released under the MIT License, see LICENSE.txt.
//*/

#include "LCWDelayParam.h"

const uint32_t delayTimeParams[LCW_DELAY_TIME_PARAMS] = {
       787 /* 0.016 */,    818 /* 0.017 */,
       848 /* 0.018 */,    877 /* 0.018 */,
       906 /* 0.019 */,    934 /* 0.019 */,
       963 /* 0.020 */,    992 /* 0.021 */,
      1022 /* 0.021 */,   1051 /* 0.022 */,
      1081 /* 0.023 */,   1112 /* 0.023 */,
      1143 /* 0.024 */,   1174 /* 0.024 */,
      1206 /* 0.025 */,   1238 /* 0.026 */,
      1271 /* 0.026 */,   1304 /* 0.027 */,
      1338 /* 0.028 */,   1373 /* 0.029 */,
      1408 /* 0.029 */,   1444 /* 0.030 */,
      1481 /* 0.031 */,   1518 /* 0.032 */,
      1556 /* 0.032 */,   1594 /* 0.033 */,
      1633 /* 0.034 */,   1673 /* 0.035 */,
      1714 /* 0.036 */,   1755 /* 0.037 */,
      1798 /* 0.037 */,   1841 /* 0.038 */,
      1885 /* 0.039 */,   1929 /* 0.040 */,
      1975 /* 0.041 */,   2021 /* 0.042 */,
      2068 /* 0.043 */,   2116 /* 0.044 */,
      2165 /* 0.045 */,   2215 /* 0.046 */,
      2266 /* 0.047 */,   2318 /* 0.048 */,
      2371 /* 0.049 */,   2425 /* 0.051 */,
      2480 /* 0.052 */,   2536 /* 0.053 */,
      2593 /* 0.054 */,   2651 /* 0.055 */,
      2710 /* 0.056 */,   2770 /* 0.058 */,
      2832 /* 0.059 */,   2895 /* 0.060 */,
      2958 /* 0.062 */,   3023 /* 0.063 */,
      3090 /* 0.064 */,   3157 /* 0.066 */,
      3226 /* 0.067 */,   3296 /* 0.069 */,
      3367 /* 0.070 */,   3440 /* 0.072 */,
      3514 /* 0.073 */,   3590 /* 0.075 */,
      3667 /* 0.076 */,   3745 /* 0.078 */,
      3825 /* 0.080 */,   3906 /* 0.081 */,
      3989 /* 0.083 */,   4074 /* 0.085 */,
      4160 /* 0.087 */,   4247 /* 0.088 */,
      4337 /* 0.090 */,   4428 /* 0.092 */,
      4520 /* 0.094 */,   4615 /* 0.096 */,
      4711 /* 0.098 */,   4809 /* 0.100 */,
      4909 /* 0.102 */,   5010 /* 0.104 */,
      5114 /* 0.107 */,   5219 /* 0.109 */,
      5327 /* 0.111 */,   5436 /* 0.113 */,
      5548 /* 0.116 */,   5661 /* 0.118 */,
      5777 /* 0.120 */,   5895 /* 0.123 */,
      6014 /* 0.125 */,   6137 /* 0.128 */,
      6261 /* 0.130 */,   6388 /* 0.133 */,
      6517 /* 0.136 */,   6648 /* 0.139 */,
      6782 /* 0.141 */,   6918 /* 0.144 */,
      7057 /* 0.147 */,   7198 /* 0.150 */,
      7342 /* 0.153 */,   7489 /* 0.156 */,
      7638 /* 0.159 */,   7790 /* 0.162 */,
      7944 /* 0.166 */,   8102 /* 0.169 */,
      8262 /* 0.172 */,   8426 /* 0.176 */,
      8592 /* 0.179 */,   8761 /* 0.183 */,
      8934 /* 0.186 */,   9109 /* 0.190 */,
      9288 /* 0.194 */,   9470 /* 0.197 */,
      9655 /* 0.201 */,   9844 /* 0.205 */,
     10036 /* 0.209 */,  10231 /* 0.213 */,
     10430 /* 0.217 */,  10633 /* 0.222 */,
     10839 /* 0.226 */,  11049 /* 0.230 */,
     11262 /* 0.235 */,  11480 /* 0.239 */,
     11701 /* 0.244 */,  11927 /* 0.248 */,
     12156 /* 0.253 */,  12390 /* 0.258 */,
     12628 /* 0.263 */,  12870 /* 0.268 */,
     13116 /* 0.273 */,  13367 /* 0.278 */,
     13622 /* 0.284 */,  13881 /* 0.289 */,
     14146 /* 0.295 */,  14415 /* 0.300 */,
     14689 /* 0.306 */,  14967 /* 0.312 */,
     15251 /* 0.318 */,  15540 /* 0.324 */,
     15834 /* 0.330 */,  16133 /* 0.336 */,
     16437 /* 0.342 */,  16747 /* 0.349 */,
     17062 /* 0.355 */,  17383 /* 0.362 */,
     17709 /* 0.369 */,  18041 /* 0.376 */,
     18379 /* 0.383 */,  18723 /* 0.390 */,
     19073 /* 0.397 */,  19429 /* 0.405 */,
     19792 /* 0.412 */,  20160 /* 0.420 */,
     20536 /* 0.428 */,  20917 /* 0.436 */,
     21306 /* 0.444 */,  21701 /* 0.452 */,
     22103 /* 0.460 */,  22513 /* 0.469 */,
     22929 /* 0.478 */,  23353 /* 0.487 */,
     23784 /* 0.495 */,  24222 /* 0.505 */,
     24669 /* 0.514 */,  25123 /* 0.523 */,
     25584 /* 0.533 */,  26054 /* 0.543 */,
     26532 /* 0.553 */,  27019 /* 0.563 */,
     27514 /* 0.573 */,  28017 /* 0.584 */,
     28529 /* 0.594 */,  29050 /* 0.605 */,
     29580 /* 0.616 */,  30119 /* 0.627 */,
     30668 /* 0.639 */,  31226 /* 0.651 */,
     31793 /* 0.662 */,  32370 /* 0.674 */,
     32958 /* 0.687 */,  33555 /* 0.699 */,
     34163 /* 0.712 */,  34781 /* 0.725 */,
     35410 /* 0.738 */,  36049 /* 0.751 */,
     36700 /* 0.765 */,  37361 /* 0.778 */,
     38034 /* 0.792 */,  38719 /* 0.807 */,
     39415 /* 0.821 */,  40123 /* 0.836 */,
     40844 /* 0.851 */,  41576 /* 0.866 */,
     42322 /* 0.882 */,  43079 /* 0.897 */,
     43850 /* 0.914 */,  44634 /* 0.930 */,
     45431 /* 0.946 */,  46242 /* 0.963 */,
     47067 /* 0.981 */,  47905 /* 0.998 */,
     48758 /* 1.016 */,  49626 /* 1.034 */,
     50508 /* 1.052 */,  51405 /* 1.071 */,
     52317 /* 1.090 */,  53245 /* 1.109 */,
     54188 /* 1.129 */,  55148 /* 1.149 */,
     56123 /* 1.169 */,  57115 /* 1.190 */,
     58124 /* 1.211 */,  59150 /* 1.232 */,
     60193 /* 1.254 */,  61254 /* 1.276 */,
     62333 /* 1.299 */,  63430 /* 1.321 */,
     64545 /* 1.345 */,  65679 /* 1.368 */,
     66832 /* 1.392 */,  68005 /* 1.417 */,
     69197 /* 1.442 */,  70409 /* 1.467 */,
     71642 /* 1.493 */,  72895 /* 1.519 */,
     74169 /* 1.545 */,  75465 /* 1.572 */,
     76782 /* 1.600 */,  78122 /* 1.628 */,
     79483 /* 1.656 */,  80868 /* 1.685 */,
     82275 /* 1.714 */,  83706 /* 1.744 */,
     85161 /* 1.774 */,  86641 /* 1.805 */,
     88145 /* 1.836 */,  89673 /* 1.868 */,
     91228 /* 1.901 */,  92808 /* 1.933 */,
     94415 /* 1.967 */,  96048 /* 2.001 */,
     97708 /* 2.036 */,  99396 /* 2.071 */,
    101112 /* 2.107 */, 102856 /* 2.143 */,
    104630 /* 2.180 */, 106433 /* 2.217 */,
    108265 /* 2.256 */, 110128 /* 2.294 */,
    112022 /* 2.334 */, 113947 /* 2.374 */,
    115904 /* 2.415 */, 117893 /* 2.456 */,
    119915 /* 2.498 */, 121970 /* 2.541 */,
    124059 /* 2.585 */, 126183 /* 2.629 */,
    128342 /* 2.674 */, 130536 /* 2.720 */
};

const float delayFbGainTable[LCW_DELAY_FB_GAIN_TABLE_SIZE] = {
    0.000000 /*    off */,
    0.243563 /*    3.3 */,
    0.314112 /*    4.0 */,
    0.383110 /*    4.8 */,
    0.448955 /*    5.8 */,
    0.510548 /*    6.9 */,
    0.567253 /*    8.1 */,
    0.618802 /*    9.6 */,
    0.665196 /*   11.3 */,
    0.706621 /*   13.3 */,
    0.743377 /*   15.5 */,
    0.775829 /*   18.1 */,
    0.804369 /*   21.2 */,
    0.829392 /*   24.6 */,
    0.851280 /*   28.6 */,
    0.870390 /*   33.2 */,
    0.887054 /*   38.4 */,
    0.901570 /*   44.4 */,
    0.914206 /*   51.3 */,
    0.925201 /*   59.2 */,
    0.934766 /*   68.3 */,
    0.943087 /*   78.6 */,
    0.950325 /*   90.4 */,
    0.956624 /*  103.8 */,
    0.962105 /*  119.2 */,
    0.966878 /*  136.7 */,
    0.971034 /*  156.7 */,
    0.974656 /*  179.4 */,
    0.977813 /*  205.3 */,
    0.980567 /*  234.7 */,
    0.982970 /*  268.1 */,
    0.985068 /*  306.1 */,
    0.986901 /*  349.2 */,
    0.988502 /*  398.2 */,
    0.989903 /*  453.8 */,
    0.991129 /*  516.8 */,
    0.992202 /*  588.2 */,
    0.993142 /*  669.2 */,
    0.993965 /*  760.8 */,
    0.994688 /*  864.6 */,
    0.995321 /*  982.0 */,
    0.995878 /* 1114.8 */,
    0.996366 /* 1265.0 */,
    0.996795 /* 1434.7 */,
    0.997173 /* 1626.4 */,
    0.997504 /* 1843.0 */,
    0.997796 /* 2087.5 */,
    0.998053 /* 2363.4 */,
    0.998280 /* 2674.7 */,
    0.998479 /* 3025.8 */,
    0.998655 /* 3421.6 */,
    0.998810 /* 3867.7 */,
    0.998947 /* 4370.4 */,
    0.999068 /* 4936.6 */,
    0.999174 /* 5574.1 */,
    0.999268 /* 6291.8 */,
    0.999352 /* 7099.4 */,
    0.999425 /* 8008.0 */,
    0.999490 /* 9029.9 */,
    0.999548 /*10178.9 */,
    0.999599 /*11470.4 */,
    0.999644 /*12921.9 */,
    0.999684 /*14552.5 */,
    0.999719 /*16384.0 */
};
