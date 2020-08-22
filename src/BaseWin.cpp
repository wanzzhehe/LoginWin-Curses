#include "BaseWin.h"
#include <curses.h>

BaseWin::BaseWin() : selected(false), scr(nullptr),
    starty(0), startx(0), height(0), width(0)
    { ;}

BaseWin::~BaseWin() {
    delwin(scr);
}

void BaseWin::Init(int y, int x, int H, int W, short p) {
    selected = false;
    scr = newwin(height = H, width = W, starty = y, startx = x);
    colorp = p;
}

bool BaseWin::ifSelected(void) {
    return selected;
}

WINDOW *BaseWin::GetWin(void) {
    return scr;
}

chtype BaseWin::Select(void) {
    chtype ch = 0;
    selected = !selected;
    Refresh();
    if(selected) ch = Read();
    return Refresh(), ch;
}