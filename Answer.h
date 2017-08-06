//
// Created by ThinkPad on 2017/8/6.
//

#ifndef PBRAIN_NEGATO_ANSWER_H
#define PBRAIN_NEGATO_ANSWER_H

class answer
{
public:
    int direction = -1;
    int dist = -1;
    answer(int direc, int distance) {
        direction = direc;
        dist = distance;
    }
    bool operator < (const answer &a)const ;
};

#endif //PBRAIN_NEGATO_ANSWER_H
