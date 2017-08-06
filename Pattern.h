//
// Created by ThinkPad on 2017/8/6.
//

#ifndef PBRAIN_NEGATO_PATTERN_H
#define PBRAIN_NEGATO_PATTERN_H

#include <stdint-gcc.h>
#include "constant.h"

struct Pattern
{
    unsigned char type = 0;//支持popcount,^,index[],&,~等操作，不支持cout数值,clz(需要减24)；
};


extern int ptnvalue[32];

#endif //PBRAIN_NEGATO_PATTERN_H
