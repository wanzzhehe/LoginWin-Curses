#ifndef __LOGINWIN_H__
#define __LOGINWIN_H__

#include "BaseWin.h"
#include "Buttom.h"
#include "InputWin.h"
#include <vector>
using std::vector;

class LoginWin : public BaseWin {
public:
    enum STATUS{
        LOGIN,
        REGISTER
    };
private:
    STATUS stat;
    Buttom Okey, Cancel;
    vector<InputWin> IW;
};

#endif