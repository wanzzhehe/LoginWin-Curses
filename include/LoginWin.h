#ifndef __LOGINWIN_H__
#define __LOGINWIN_H__

#include "BaseWin.h"
#include "Buttom.h"
#include "InputWin.h"
#include <vector>
#include <curses.h>
#include <string>
using std::vector;
using std::string;

class LoginWin : public BaseWin {
public:
    enum STATUS{
        LOGIN,
        REGISTER
    };
private:
    STATUS stat;
    Buttom B_Okey, B_Cancel;
    vector<InputWin> IW;
    vector<BaseWin *> list;
    string topmesg;
public:
    LoginWin();
    void Init(int starty, int startx, int height, int width, short colorp, STATUS stat, string topmesg);
    chtype Read();
};

#endif