#include "LoginWin.h"

void LoginWin::Init(int y, int x, int H, int W, short p0, short p1, short p2, short p3, STATUS s, string tm) {
    BaseWin::Init(y, x, H, W, p0);
    stat = s, topmesg = tm;
    if(topmesg.length() == 0) {
        switch(stat) {
            LOGIN: 
                topmesg = "Login";
                break;
            REGISTER:
                topmesg = "Register";
                break;
        }
    }
    B_Okey.Init(starty + height - 2, startx + width / 4 - 4, 1, 8, p1, "< Okey >");
    B_Cancel.Init(starty + height - 2, startx + 3 * width / 4 - 4, 1, 8, p1, "<Cancel>");
    //IW.push_back(InputWin());
    //IW.push_back(InputWin());
    //IW[0].Init(starty + 3, startx + 11, 1, width - 12, p2, p3, InputWin::NAME);
    //IW[1].Init(starty + 5, startx + 11, 1, width - 12, p2, p3, InputWin::PASS);
    //if(REGISTER == stat) {
    //    IW.push_back(InputWin());
    //    IW[2].Init(starty + 7, )
    switch(stat) {
        case LOGIN: {
            IW.push_back(InputWin());
            IW.push_back(InputWin());
            IW[0].Init(starty + 3, startx + 11, 1, width - 12, p2, p3, InputWin::NAME);
            IW[1].Init(starty + 5, startx + 11, 1, width - 12, p2, p3, InputWin::PASS);
            break;
        }
        case REGISTER: {
            IW.push_back(InputWin());
            IW.push_back(InputWin());
            IW.push_back(InputWin());
            IW[0].Init(starty + 3, startx + 19, 1, width - 20, p2, p3, InputWin::NAME);
            IW[1].Init(starty + 5, startx + 19, 1, width - 20, p2, p3, InputWin::PASS);
            IW[2].Init(starty + 7, startx + 19, 1, width - 20, p2, p3, InputWin::PASS);
            break;
        }
    }
}