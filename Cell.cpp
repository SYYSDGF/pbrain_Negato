//
// Created by ThinkPad on 2017/8/6.
//

#include "Cell.h"

void Ceil::checkFour(set<answer> &ret, int direc, int color) {
    if (ptn[color ^ 1][direc].type != (unsigned char)0)
        return;
    switch (ptn[color][direc].type)
    {
        case 15:
            ret.insert(answer(direc, 4));
            break;
        case 23:
            ret.insert(answer(direc, 3));
            break;
        case 27:
            ret.insert(answer(direc, 2));
            break;
        case 29:
            ret.insert(answer(direc, 1));
            break;
        case 30:
            ret.insert(answer(direc, 0));
            break;
        default:
            break;
    }
}

void Ceil::checkThree(set<answer> &ret, int direc, int color) {
    if (ptn[color ^ 1][direc].type != (unsigned char)0)
        return;
    if (ptn[color][direc].type == (unsigned char)14) {
        ret.insert(answer(direc, 0));
        ret.insert(answer(direc, 4));
    }
}

bool Ceil::checkFive(int direc, int color) {
    return ptn[color][direc].type == (unsigned char) 31;
}

Ceil::Ceil() {
    for (int color = 0; color < 2; color++) {
        for (int direc = 0; direc < dirnum / 2; direc++) {
            value[color][direc] = 0;
        }
    }
}

void Ceil::updateType(int direc, int color, int dist) {
    ptn[color][direc].type ^= ((unsigned char) 1 << dist);
    if (!((ptn[color][direc].type != (unsigned char) 0) //不同时不为零
          && (ptn[color ^ 1][direc].type != (unsigned char) 0))) {
        value[color][direc] = ptnvalue[ptn[color][direc].type];
        value[color ^ 1][direc] = ptnvalue[ptn[color ^ 1][direc].type];
    } else { //同时不为零,双方均无有效棋型
        value[color][direc] = value[color ^ 1][direc] = 0;
    }
}




int Ceil::getGridValue(int color) {
    int retvalue = 0;
    for (int dir = 0; dir < dirnum / 2; dir++) {
        retvalue += (value[color][dir] - value[color ^ 1][dir]);
    }
    return retvalue;
}

int Ceil::getLineValue(int direc, int color) {
    return value[color][direc] - value[color ^ 1][direc];
}

int Ceil::getDirecValue(int direc, int color, int dist) {
    unsigned char mask = ptn[color][direc].type;
    mask ^= ((unsigned char) 1 << dist);
    if (!((mask != (unsigned char) 0) //不同时不为零
          && (ptn[color ^ 1][direc].type != (unsigned char) 0)))
        return ptnvalue[mask] - ptnvalue[ptn[color ^ 1][direc].type];
    return 0;//同时不为零,双方均无有效棋型
}
