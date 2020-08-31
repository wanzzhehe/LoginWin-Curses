#ifndef __INPUTWIN_H__
#define __INPUTWIN_H__

#include "BaseWin.h"
#include <string>
#include <curses.h>
using std::string;

using uint = unsigned int;

class InputWin : public BaseWin {
public:
    enum STATUS{
        NAME,
        PASS,
        TEXT
    };
private:
    string text;
    short colorp1;
    uint startn, curn;
    STATUS stat;
public:
    InputWin();
    void Init(int starty, int startx, int height, int width, short colorp0, short colorp1, STATUS stat);
    void Refresh(void);
    chtype Read(void);
    STATUS GetStatus(void);
    string GetText(void);
private:
    void AddCh(chtype ch);
    void RefreshNAME(short colorp);
    void RefreshPASS(short colorp);
    void RefreshTEXT(short colorp);
};

#endif