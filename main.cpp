#include "Buttom.h"
#include "InputWin.h"
#include "LoginWin.h"
using namespace std;

InputWin NAME, PASS;
BaseWin *list[4];
LoginWin LW;

int main() {
    initscr();
    start_color();
    curs_set(0);
    init_pair(1, COLOR_BLUE, COLOR_GREEN);
    init_pair(2, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    LW.Init(1, 1, 11, 80, 1, 1, 3, 2, LoginWin::REGISTER);
    LW.Select();
    getchar();
    endwin();
//    list[0] = new InputWin();
//    list[1] = new InputWin();
//    list[2] = new Buttom();
//    list[3] = new Buttom();
//    mvwprintw(stdscr, 5, 0, "Username: ");
//    mvwprintw(stdscr, 7, 0, "Password: ");
//    wrefresh(stdscr);
//    ((InputWin *)list[0])->Init(5, 10, 1, 40, 1, 2, InputWin::NAME);
//    ((InputWin *)list[1])->Init(7, 10, 1, 40, 1, 2, InputWin::PASS);
//    ((Buttom *)list[2])->Init(9, 16, 1, 8, 1, "<  OK  >");
//    ((Buttom *)list[3])->Init(9, 36, 1, 8, 1, "<Cancel>");
//    for(int i = 0; i < 4; ++i) list[i]->Refresh();
//    int i;
//    for(i = 0; ; ++i, i %= 4) {
//        chtype ch = list[i]->Select();
//        switch(ch) {
//            case 0x0A: {
//                if(i == 2 || i == 3) goto BREAK;
//                break;
//            }
//            case 0x09: {
//                break;
//            }
//            case KEY_UP: {
//                if(i == 0) i = 1;
//                else if(i == 1) i = 3;
//                else if(i == 2 || i == 3) i = 0;
//                break;
//            }
//            case KEY_DOWN: {
//                if(i == 2) i = 3;
//                break;
//            }
//            case KEY_LEFT: {
//                if(i == 3) i = 1;
//                break;
//            }
//            case KEY_RIGHT: {
//                if(i == 3) i = 1;
//                break;
//            }
//            default: {
//                break;
//            }
//        }
//    }
//BREAK:
//    curs_set(0);
//    endwin();
//    if(i == 2) {
//        printf("Your username is \"%s\"\n", (((InputWin *)list[0])->GetText()).c_str());
//        printf("Your password is \"%s\"\n", (((InputWin *)list[1])->GetText()).c_str());
//    } else if(i == 3) {
//        printf("You cancel your login.\n");
//    }
    return 0;
}