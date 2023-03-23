//
// Created by thene on 14.04.2023.
//

#ifndef INC_6_TASK_CLASS_H
#define INC_6_TASK_CLASS_H


class Point
{
private:
    double x, y;
public:
    Point() {}
    Point(double x_, double y_)
            : x(x_), y(y_) {}
    int getx();
    int gety();
    bool operator> (Point &p);
    bool operator!= (Point &p);
    bool operator> (int a);
    bool operator!= (int a);
    ~Point() = default;
};


#endif //INC_6_TASK_CLASS_H
