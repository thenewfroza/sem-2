//
// Created by thene on 14.04.2023.
//

#include "class.h"
int Point::getx()
{
    return x;
}

int Point::gety()
{
    return y;
}

bool Point::operator!=(Point &p)
{
    return (p.getx() != getx() && p.gety() != gety());
}

bool Point::operator>(Point &p)
{
    if (getx() > p.getx() && gety() > p.gety())
    {
        return true;
    }
    return false;
}

bool Point::operator> (int a)
{
    if (getx() > a && gety() > a)
    {
        return true;
    }
    return false;
}

bool Point::operator!= (int a)
{
    if (getx() != a && gety() != a)
    {
        return true;
    }
    return false;
}