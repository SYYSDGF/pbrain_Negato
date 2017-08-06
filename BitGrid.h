//
// Created by ThinkPad on 2017/8/6.
//

#ifndef PBRAIN_NEGATO_BITGRID_H
#define PBRAIN_NEGATO_BITGRID_H

#include "constant.h"
#include <vector>
#include <stdint-gcc.h>

using namespace std;

struct point
{
    int x;
    int y;
    int value;
    int color;
    point() {
        x = y = -1;
        value = 0;
        color = -1;
    }
    point(int xx, int yy, int clr) {
        x = xx;
        y = yy;
        value = 0;
        color = clr;
    }
    bool operator < (const point &a)const ;
};

bool comp_point(const point &a, const point &b);

class Bitgrid
{
public:
    long long state[4];
public:
    void init();
    void assign(int64_t a, int64_t b, int64_t c, int64_t d);
    void change(int x, int y);
    bool check(int x, int y);
    Bitgrid operator & (const Bitgrid &a);
    Bitgrid operator ~ ();
    Bitgrid operator ^ (const Bitgrid &a);
    Bitgrid operator | (const Bitgrid &a);
    void debug();
    vector<point> getOne();

};


bool inMap(int x, int y);

extern int negdx[24];
extern int negdy[24];

extern int affdx[32];
extern int affdy[32];

extern Bitgrid near[gridsize][gridsize];
extern Bitgrid farf[gridsize][gridsize];
extern Bitgrid affect[gridsize][gridsize];



#endif //PBRAIN_NEGATO_BITGRID_H
