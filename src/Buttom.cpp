#include "Buttom.h"
#include <string>
using std::string;

Buttom::Buttom() {
    mesg = "";
}

void Buttom::Init(int y, int x, int H, int W, short p, string m) {
    BaseWin::Init(y, x, H, W, p);
    SetTEXT(m);
}

void Buttom::SetTEXT(string m) {
    mesg = m;
}

chtype Buttom::Read(void) {
    curs_set(0);
    keypad(scr, true);
    noecho();
    chtype ch;
    do{
        ch = wgetch(scr);
    }while(!(ch == KEY_UP || ch == KEY_DOWN ||
        ch == KEY_LEFT || ch == KEY_RIGHT ||
        ch == 0x0A || ch == 0x09));
    Select();
    keypad(scr, false);
    echo();
    return ch;
}

void Buttom::Refresh(void) {
    attr_t attr;
    if(selected) attr = A_STANDOUT;
    else attr = A_NORMAL;
    for(int i = 0; i < height; ++i) {
        mvwprintw(scr, i, 0, mesg.substr(i * width, width).c_str());
        mvwchgat(scr, i, 0, -1, attr, colorp, NULL);
    }
    wrefresh(scr);
}