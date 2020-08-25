#include "LoginWin.h"

void LoginWin::Init(int y, int x, int H, int W, short p0, short p1, short p2, short p3, STATUS s, string tm) {
    BaseWin::Init(y, x, H, W, p0);
    stat = s, topmesg = tm;
    if(topmesg.length() == 0) {
        switch(stat) {
            case LOGIN: 
                topmesg = "Login";
                break;
            case REGISTER:
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
            list.push_back(&IW[0]);
            list.push_back(&IW[1]);
            break;
        }
        case REGISTER: {
            IW.push_back(InputWin());
            IW.push_back(InputWin());
            IW.push_back(InputWin());
            IW[0].Init(starty + 3, startx + 19, 1, width - 20, p2, p3, InputWin::NAME);
            IW[1].Init(starty + 5, startx + 19, 1, width - 20, p2, p3, InputWin::PASS);
            IW[2].Init(starty + 7, startx + 19, 1, width - 20, p2, p3, InputWin::PASS);
            list.push_back(&IW[0]);
            list.push_back(&IW[1]);
            list.push_back(&IW[2]);
            break;
        }
    }
    list.push_back(&B_Okey);
    list.push_back(&B_Cancel);
    curn = 0;
}

void LoginWin::Refresh(void) {
    switch(stat) {
        case LOGIN:
            RefreshLOGIN();
            break;
        case REGISTER:
            RefreshREGISTER();
            break;
    }
    for(int i = 0; i < height; ++i) 
        mvwchgat(scr, i, 0, -1, A_NORMAL, colorp, NULL);
    mvwchgat(scr, 1, 0, -1, A_BOLD, colorp, NULL);
    wrefresh(scr);
    for(vector<BaseWin *>::iterator i = list.begin(); i != list.end(); ++i)
        (*i)->Refresh();
}

void LoginWin::RefreshLOGIN(void) {
    mvwprintw(scr, 1, (width - topmesg.length()) / 2, topmesg.c_str());
    mvwprintw(scr, 3, 1, "Username: ");
    mvwprintw(scr, 5, 1, "Password: ");
}

void LoginWin::RefreshREGISTER(void) {
    mvwprintw(scr, 1, (width - topmesg.length()) / 2, topmesg.c_str());
    mvwprintw(scr, 3, 1, "        Username: ");
    mvwprintw(scr, 5, 1, "        Password: ");
    mvwprintw(scr, 7, 1, "Confirm Password: ");
}

chtype LoginWin::Read(void) {
    chtype ch;
    for(; ; ) {
        ch = list[curn]->Select();
        switch(ch) {
            case 0x09: {
                curn = (curn += 1) % list.size();
                break;
            }
            case KEY_BTAB: {
                if(curn == 0) curn = list.size() - 1;
                else --curn;
                break;
            }
            case 0x0A: {
                if(curn == list.size() - 2) return 1;
                if(curn == list.size() - 1) return 0;
                ++curn;
                break;
            }
            case KEY_UP: {
                break;
            }
            case KEY_DOWN: {
                break;
            }
            case KEY_LEFT: {
                break;
            }
            case KEY_RIGHT: {
                break;
            }
        }
    }
    return ch;
}