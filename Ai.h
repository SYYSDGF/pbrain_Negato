//
// Created by ThinkPad on 2017/8/6.
//

#ifndef PBRAIN_NEGATO_AI_H
#define PBRAIN_NEGATO_AI_H

#include "Board.h"
#include "jsoncpp/json.h"

class Ai
{
private:
    Board brd;
    int botColor;
    int turnTD = 0;
    point historyPoints[gridsize * gridsize];
public:
    void getBotzoneInput() {
        string str;
        getline(cin,str);
        Json::Reader reader;
        Json::Value input;
        reader.parse(str,input);
        int turnID = input["responses"].size();
        botColor = input["requests"][(Json::Value::UInt) 0]["x0"].asInt() < 0 ? black : white;
        int x, y;
        for(int i=0;i<turnID;i++)
        {
            x=input["requests"][i]["x"].asInt();
            y=input["requests"][i]["y"].asInt();
            if(x>=0)
            {
                brd.change(point(x, y, botColor ^ 1));
            }
            x=input["responses"][i]["x"].asInt();
            y=input["responses"][i]["y"].asInt();
            if(x>=0)
            {
                brd.change(point(x, y, botColor));
            }
        }
        x=input["requests"][turnID]["x"].asInt();
        y=input["requests"][turnID]["y"].asInt();
        if(x>=0)
        {
            brd.change(point(x, y, botColor ^ 1));
        }
    }
    void debug() {
        brd.debug();
    }

};

#endif //PBRAIN_NEGATO_AI_H
