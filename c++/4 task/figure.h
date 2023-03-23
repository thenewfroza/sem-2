//
// Created by thene on 14.04.2023.
//

#ifndef INC_4_TASK_FIGURE_H
#define INC_4_TASK_FIGURE_H

#include <iostream>
#include <cmath>
#include <string>


struct point {
    double x;
    double y;

    point() {}

    point(double a, double b) {
        this->x = a;
        this->y = b;
    }

    ~point() {}
};

class IGeoFig {
public:
    virtual double square() = 0;

    virtual double perimeter() = 0;

    IGeoFig() {}

    ~IGeoFig() {}
};

class CVector2D {
public:
    double x, y;

    CVector2D() {}

    CVector2D(double, double);

    ~CVector2D() {}
};

class IPhysObject {
public:
    virtual double mass() = 0;

    virtual CVector2D position() = 0;

    virtual bool operator==(IPhysObject &) = 0;

    virtual bool operator<(IPhysObject &) = 0;

    IPhysObject() {}

    ~IPhysObject() {}
};

class IPrintable {
public:
    virtual void draw() = 0;

    IPrintable() {}

    ~IPrintable() {}
};

class IDialogInitiable {
public:
    virtual void initFromDialog() = 0;

    IDialogInitiable() {}

    ~IDialogInitiable() {}
};

class BaseCObject {
public:
    virtual const std::string classname() = 0;

    virtual unsigned int size() = 0;

    BaseCObject() {}

    ~BaseCObject() {}
};

class Rectangle
        : public IGeoFig,
          public CVector2D,
          public IPhysObject,
          public IPrintable,
          public IDialogInitiable,
          public BaseCObject {
private:
    point a, b, c;
    double linear_area = 1;

    double dist(point, point);

    std::string name = "rectangle";
public:
    Rectangle() {}

    ~Rectangle() {}

    double square() override;

    double perimeter() override;

    double mass() override;

    CVector2D position() override;

    bool operator==(IPhysObject &) override;

    bool operator<(IPhysObject &) override;

    void draw() override;

    void initFromDialog() override;

    const std::string classname() override;

    unsigned int size() override;
};

class Trapeze
        : public IGeoFig,
          public CVector2D,
          public IPhysObject,
          public IPrintable,
          public IDialogInitiable,
          public BaseCObject {
private:
    point a, b, c, d;

    double dist(point, point);

    double linear_area = 1;
    std::string name = "trapeze";
public:
    Trapeze() {}

    ~Trapeze() {}

    double square() override;

    double perimeter() override;

    double mass() override;

    CVector2D position() override;

    bool operator==(IPhysObject &) override;

    bool operator<(IPhysObject &) override;

    void draw() override;

    void initFromDialog() override;

    const std::string classname() override;

    unsigned int size() override;
};


#endif //INC_4_TASK_FIGURE_H
