#include "LoginWin.h"

LoginWin::LoginWin() { ;}

void LoginWin::Init(int y, int x, int H, int W, short p, STATUS s, string tm) {
    BaseWin::Init(y, x, H, W, p);
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
    switch(stat) {
        LOGIN:
            
            break;
        REGISTER:
            break;
    }
}