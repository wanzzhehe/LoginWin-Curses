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
    void Init(int starty, int startx, int height, int width, short colorpBase, short colorpButtom, short colorpInput0, short colorpInput1, STATUS stat, string topmesg = "");
    chtype Read();
    void Refresh();
private:
    void RefreshLOGIN();
    void RefreshREGISTER();
};

#endif