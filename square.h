#pragma once
#include "Position.h"
class square :
    public Position// ����������� �� ������ Position c �������� public
{
public:
    square();
    square(int x, int  y, int dl);
    ~square();
private:
    int dlinna;
public:
    int get_dl();
};


