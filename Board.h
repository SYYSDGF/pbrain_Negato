//
// Created by ThinkPad on 2017/8/6.
//

#ifndef PBRAIN_NEGATO_BOARD_H
#define PBRAIN_NEGATO_BOARD_H

#include "constant.h"
#include "Cell.h"
#include "BitGrid.h"
#include <set>
#include <iostream>

class Board
{
private:
    Ceil ceil[gridsize][gridsize];
    Bitgrid table[2];
public:
    Board();
    void updateType(point change);
    void getnearPoint(vector<point> &ret, int color);
    void getneighPoint(vector<point> &ret, int color);
    Bitgrid getnearblank();
    Bitgrid getneighblank();
    void change(point p);
    int evalPoint(int color, int x, int y);
    int evalGrid_near(int color);
    int evalGrid_neigh(int color);
    //下一步棋后形成的棋型
    bool checkFive(point p);//五连
    void checkFour(set<point> &ret, point p);//冲四
    void checkThree(set<point> &ret, point p);//活三
    //下一步棋后形成的棋型
    void debug();
};


#endif //PBRAIN_NEGATO_BOARD_H
