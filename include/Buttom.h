#ifndef __BUTTOM_H__
#define __BUTTOM_H__

#include "BaseWin.h"
#include <string>
using std::string;

class Buttom : public BaseWin {
private:
    string mesg;
public:
    Buttom();
    void Init(int starty, int startx, int height, int width, short colorp, string mesg);

    void SetTEXT(string mesg);
    chtype Read(void);
    void Refresh(void);
};

#endif