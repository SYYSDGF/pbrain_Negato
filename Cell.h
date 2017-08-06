//
// Created by ThinkPad on 2017/8/6.
//

#ifndef PBRAIN_NEGATO_CELL_H
#define PBRAIN_NEGATO_CELL_H

#include "constant.h"
#include <vector>
#include <set>
#include "Pattern.h"
#include "Answer.h"
#include "BitGrid.h"

using namespace std;



class Ceil
{
private:
    Pattern ptn[2][dirnum / 2];
    int value[2][dirnum / 2];
public:
    Ceil();
    void updateType(int direc, int color, int dist);
    int getLineValue(int direc, int color);
    int getDirecValue(int direc, int color, int dist);
    int getGridValue(int color);
    bool checkFive(int direc, int color);
    void checkFour(set<answer> &ret, int direc, int color);
    void checkThree(set<answer> &ret, int direc, int color);
};



#endif //PBRAIN_NEGATO_CELL_H
