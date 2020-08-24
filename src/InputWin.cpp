#include "InputWin.h"
#include <string>
#include <curses.h>
using std::string;

InputWin::InputWin() : text("") { ;}

void InputWin::Init(int y, int x, int H, int W, short p0, short p1, STATUS s) {
    BaseWin::Init(y, x, H, W, p0);
    colorp1 = p1, stat = s;
    curn = startn = 0;
}

void InputWin::Refresh(void) {
    short cp;
    if(selected) cp = colorp1;
    else cp = colorp;
    switch(stat) {
        case NAME: 
            RefreshNAME(cp);
            break;
        case PASS:
            RefreshPASS(cp);
            break;
        case TEXT:
            RefreshTEXT(cp);
            break;
    }
}

void InputWin::RefreshNAME(short cp) {
    uint tp = curn - startn;
    wclear(scr);
    mvwprintw(scr, 0, 0, text.substr(startn, width).c_str());
    mvwchgat(scr, 0, 0, -1, A_NORMAL, cp, NULL);
    wmove(scr, 0, tp);
    wrefresh(scr);
}

void InputWin::RefreshPASS(short cp) {
    uint tp = curn - startn;
    uint cnt;
    cnt = (cnt = text.length() - startn) > width ? width : cnt;
    wmove(scr, 0, 0);
    wclear(scr);
    for(uint i = 0; i < cnt; ++i) waddch(scr, '*');
    mvwchgat(scr, 0, 0, -1, A_NORMAL, cp, NULL);
    wmove(scr, 0, tp);
    wrefresh(scr);
}

void InputWin::RefreshTEXT(short cp) {
    // TODO
}

chtype InputWin::Read(void) {
    chtype ch;
    curs_set(1);
    wmove(scr, 0, curn - startn);
    keypad(scr, true);
    noecho();
    do{
        ch = wgetch(scr);
        if(ch == 0x0A || ch == 0x09 || ch == KEY_UP || ch == KEY_DOWN) break;
        AddCh(ch);
        Refresh();
    }while(true);
    Select();
    keypad(scr, false);
    echo();
    return ch;
}

void InputWin::AddCh(chtype ch) {
    switch(ch) {
        case KEY_LEFT: {
            if(curn == 0) break;
            --curn;
            if(curn < startn) --startn;
            break;
        }
        case KEY_RIGHT: {
            if(curn == text.length()) break;
            ++curn;
            if(curn - startn >= width) ++startn;
            break;
        }
        case 330: {
            if(curn == text.length()) break;
            string t0 = text.substr(0, curn);
            string t1 = text.substr(curn + 1);
            text = t0 + t1;
            break;
        }
        case KEY_BACKSPACE: {
            if(curn == 0) break;
            string t0 = text.substr(0, curn - 1);
            string t1 = text.substr(curn);
            text = t0 + t1;
            --curn;
            if(curn < startn) --startn;
            break;
        }
        default: {
            if(!isprint(ch)) break;
            string t0 = text.substr(0, curn);
            string t1 = text.substr(curn);
            text = t0 + (char)ch + t1;
            ++curn;
            if(curn - startn >= width) ++startn;
            break;
        }
    }
}

InputWin::STATUS InputWin::GetStatus(void) {
    return stat;
}

string InputWin::GetText(void) {
    return text;
}