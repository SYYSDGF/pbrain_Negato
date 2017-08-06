//
// Created by ThinkPad on 2017/8/6.
//

#include <algorithm>
#include "Board.h"

Board::Board() {
    table[0].init();
    table[1].init();
}

void Board::updateType(point change) {
    for (int dir = 4; dir < dirnum; dir++) {
        for (int dist = 0; dist <= 4; dist++) {
            int tempx = change.x + negdx[dir] * dist;
            int tempy = change.y + negdy[dir] * dist;
            if (!inMap(tempx, tempy))
                continue;
            ceil[tempx][tempy].updateType(dir - 4, change.color, dist);
        }
    }
}

void Board::getneighPoint(vector<point> &ret, int color) {
    Bitgrid reachblank = getneighblank();
    ret = reachblank.getOne();
    for (int i = 0; i < ret.size(); i++) {
        ret[i].color = color;
        ret[i].value = evalPoint(color, ret[i].x, ret[i].y);
    }
    sort(ret.begin(), ret.end(), comp_point);
}

void Board::getnearPoint(vector<point> &ret, int color) {
    Bitgrid reachblank = getnearblank();
    ret = reachblank.getOne();
    for (int i = 0; i < ret.size(); i++) {
        ret[i].color = color;
        ret[i].value = evalPoint(color, ret[i].x, ret[i].y);
    }
    sort(ret.begin(), ret.end(), comp_point);
}

Bitgrid Board::getneighblank() {
    Bitgrid ret;
    ret.init();
    Bitgrid all = table[black] | table[white];
    vector<point> curr = all.getOne();
    for (int i = 0; i < curr.size(); i++) {
        ret = ret | farf[curr[i].x][curr[i].y];
    }
    ret = ret & ~all;
    return ret;
}

Bitgrid Board::getnearblank() {
    Bitgrid ret;
    ret.init();
    Bitgrid all = table[black] | table[white];
    vector<point> curr = all.getOne();
    for (int i = 0; i < curr.size(); i++) {
        ret = ret | near[curr[i].x][curr[i].y];
    }
    ret = ret & ~all;
    return ret;
}

void Board::change(point p) {
    updateType(p);
    table[p.color].change(p.x, p.y);
}

int Board::evalGrid_near(int color) {
    Bitgrid nearblank = getnearblank();
    Bitgrid tempAll = nearblank | (table[black] | table[white]);
    vector<point> point_blank = tempAll.getOne();
    int retvalue = 0;
    for (int i = 0; i < point_blank.size(); i++) {
        retvalue += ceil[point_blank[i].x][point_blank[i].y].getGridValue(color);
    }
    return retvalue;
}

int Board::evalGrid_neigh(int color) {
    Bitgrid neighblank = getneighblank();
    Bitgrid tempAll = neighblank | (table[black] | table[white]);
    vector<point> point_blank = tempAll.getOne();
    int retvalue = 0;
    for (int i = 0; i < point_blank.size(); i++) {
        retvalue += ceil[point_blank[i].x][point_blank[i].y].getGridValue(color);
    }
    return retvalue;
}

void Board::debug() {
    cout << "table" << endl;
    cout << "   ";
    for (int i = 0; i < gridsize; i++) {
        if (i < 9)
            cout << i << " ";
        else
            cout << i;
    }
    cout << endl;
    for (int i = 0; i < gridsize; i++) {
        if (i < 10)
            cout << " ";
        cout << i << " ";
        for (int j = 0; j < gridsize; j++) {
            if (table[black].check(j,i))
                cout << "B ";
            else if (table[white].check(j,i))
                cout << "W ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

bool Board::checkFive(point p) {
    for (int dir = 4; dir < dirnum; dir++) {
        for (int dist = 0; dist <= 4; dist++) {
            int tempx = p.x + negdx[dir] * dist;
            int tempy = p.y + negdy[dir] * dist;
            if (!inMap(tempx, tempy))
                continue;
            if (ceil[tempx][tempy].checkFive(dir - 4, p.color))
                return true;
        }
    }
    return false;
}

void Board::checkFour(set<point> &ret, point p) {
    for (int dir = 4; dir < dirnum; dir++) {
        for (int dist = 0; dist <= 4; dist++) {
            set<answer> temp;
            int tempx = p.x + negdx[dir] * dist;
            int tempy = p.y + negdy[dir] * dist;
            if (!inMap(tempx, tempy))
                continue;
            ceil[tempx][tempy].checkFour(temp, dir - 4, p.color);
            for (auto iter = temp.begin(); iter != temp.end(); iter++) {
                point curr;
                curr.x = p.x + negdx[dir] * (dist - iter->dist);
                curr.y = p.y + negdy[dir] * (dist - iter->dist);
                curr.color = p.color;
                curr.value = CHECKVALUE;
                ret.insert(curr);
            }
        }
    }
}

void Board::checkThree(set<point> &ret, point p) {
    for (int dir = 4; dir < dirnum; dir++) {
        for (int dist = 0; dist <= 4; dist++) {
            set<answer> temp;
            int tempx = p.x + negdx[dir] * dist;
            int tempy = p.y + negdy[dir] * dist;
            if (!inMap(tempx, tempy))
                continue;
            ceil[tempx][tempy].checkThree(temp, dir - 4, p.color);
            for (auto iter = temp.begin(); iter != temp.end(); iter++) {
                point curr;
                curr.x = p.x + negdx[dir] * (dist - iter->dist);
                curr.y = p.y + negdy[dir] * (dist - iter->dist);
                curr.color = p.color;
                curr.value = CHECKVALUE;
                ret.insert(curr);
            }
        }
    }
}

int Board::evalPoint(int color, int x, int y) {
    int retvalue = 0;
    for (int dir = 4; dir < dirnum; dir++) {
        for (int dist = 0; dist <= 4; dist++) {
            int tempx = x + negdx[dir] * dist;
            int tempy = y + negdy[dir] * dist;
            if (!inMap(tempx, tempy))
                continue;
            retvalue += ceil[tempx][tempy].getDirecValue(dir - 4, color, dist);
        }
    }
    return retvalue;
}
