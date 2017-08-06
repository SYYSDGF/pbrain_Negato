//
// Created by ThinkPad on 2017/8/6.
//

#ifndef PBRAIN_NEGATO_DEBUG_CODE_H
#define PBRAIN_NEGATO_DEBUG_CODE_H

#include "Board.h"

void debug_pointvector(vector<point> temp) {
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i].x << ", " << temp[i].y << ", "
             << temp[i].color << "," << temp[i].value << endl;
    }
    cout << "-------------" << endl;
}

void debug_pointset(set<point> temp) {
    cout << "size: " << temp.size() << endl;
    for (auto iter = temp.begin(); iter != temp.end(); iter++) {
        cout << iter->x << ", " << iter->y << ", " << iter->color
             << ", " << iter->value << endl;
    }
    cout << "-------------" << endl;
}

void debug_checkFive(bool outcome) {
    if (outcome)
        cout << "Five OK!" << endl;
    else
        cout << "Not Five!" << endl;
}

#endif //PBRAIN_NEGATO_DEBUG_CODE_H
