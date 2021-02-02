#pragma once
#include "Position.h"
class circle :
    public Position// наследуется от класса Position c доступом public
{
public:
    circle();
    circle(int x, int  y, int r);
    ~circle();
private:
    int radius;
public:
    int get_r();
};
