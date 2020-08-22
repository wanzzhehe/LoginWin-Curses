#ifndef __BASEWIN_H__
#define __BASEWIN_H__

#include <curses.h>

class BaseWin{
protected:
    WINDOW *scr;
    int starty, startx, height, width;
    bool selected;
    short colorp;
public:
    BaseWin();
    ~BaseWin();
    virtual void Init(int starty, int startx, int height, int width, short colorp);
    bool ifSelected(void);
    WINDOW *GetWin(void);

    chtype Select(void);
    virtual chtype Read(void) = 0;
    virtual void Refresh(void) = 0;
};

#endif