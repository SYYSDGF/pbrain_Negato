#include <iostream>
#include "Ai.h"
#include "Board.h"
#include "jsoncpp/json.h"
#include "debug__code.h"
using namespace std;


/*
int main() {

    Board brd;
    brd.debug();
    brd.change(point(0,0,white));
    brd.change(point(5,5,white));
    brd.change(point(6,6,black));
    brd.change(point(7,7,black));
    //brd.change(point(6,6,white));
    brd.change(point(8,8,black));
    //brd.change(point(9,9,black));
    //brd.change(point(10,10,black));
    brd.debug();
    //brd.change(point(10,10,black));
    //brd.debug();
    //Bitgrid test = brd.getnearblank();
    //test.debug();
    vector<point> temp;
    brd.getnearPoint(temp, black);
    debug_pointvector(temp);
    //set<point> temp;
    //brd.checkFour(temp,point(9,9,black));
    //debug_checkFive(out);
    //debug_pointset(temp);
    set<point> test;
    test.insert(point(10,10,1));
    test.insert(point(6,6,0));
    cout << test.size() << endl;
}
 */
/*
int main() {
    Ai yuki;
    yuki.debug();
    yuki.getBotzoneInput();
    yuki.debug();
}*/

int main() {
    Board brd;
    string str;
    getline(cin,str);
    Json::Reader reader;
    Json::Value input;
    reader.parse(str,input);
    int turnID = input["responses"].size();
    int botColor = input["requests"][(Json::Value::UInt) 0]["x"].asInt() < 0 ? black : white;
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
    brd.debug();
    //set<point> temp;
    int myx = input["responses"][turnID - 1]["x"].asInt();
    int myy = input["responses"][turnID - 1]["y"].asInt();
    int enemyx = input["requests"][turnID]["x"].asInt();
    int ennmyy = input["requests"][turnID]["y"].asInt();
    //cout << enemyx << ", " << ennmyy << endl;
    //brd.checkFour(temp, point(enemyx, ennmyy, botColor ^ 1));
    //debug_pointset(temp);
    vector<point> curr;
    brd.getnearPoint(curr, botColor);
    debug_pointvector(curr);
    //Bitgrid test = brd.getnearblank();
    //test.debug();
}
/*
int main() {
    string str;
    Json::Reader reader;
    Json::Value input;
    reader.parse(str,input);
    int turnID = input["responses"].size();
    //int botColor = input["requests"][(Json::Value::UInt) 0]["x0"].asInt() < 0 ? black : white;
    int x, y;
}*/
/*
int main() {
    Board brd;
    brd.debug();
    brd.change(point(7,7,black));
    brd.change(point(6,7,black));
    brd.debug();
    cout << brd.evalPoint(black,5,7) << endl;
    vector<point> temp;
    brd.getnearPoint(temp, black);
    debug_pointvector(temp);
}
*/