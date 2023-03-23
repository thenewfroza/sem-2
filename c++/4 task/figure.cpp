#include "figure.h"


CVector2D::CVector2D(double xx, double yy)
{
    this->x = xx;
    this->y = yy;
}

double Rectangle::dist(point point_1, point point_2)
{
    double a1 = (point_1.x - point_2.x)*(point_1.x - point_2.x);
    double a2 = (point_1.y - point_2.y)*(point_1.y - point_2.y);
    return(sqrt(a1 + a2));
}

double Rectangle::square()
{
    return dist(this->a, this->c)*dist(this->b, this->c);
}

double Rectangle::perimeter()
{
    return 2*(dist(this->a, this->c) + dist(this->b, this->c));
}

double Rectangle::mass()
{
    return(this->square()*linear_area);
}

CVector2D Rectangle::position()
{
    double xx = (this->a.x + this->b.x)/2;
    double yy = (this->a.y + this->b.y)/2;
    return(CVector2D(xx, yy));
}

bool Rectangle::operator == (IPhysObject& obj)
{
    if(mass() == obj.mass())
    {
        return true;
    }
    return false;
}

bool Rectangle::operator < (IPhysObject& obj)
{
    if(this->mass() < obj.mass())
    {
        return true;
    }
    return false;
}

void Rectangle::draw()
{
    std::cout << "Координаты точек\n";
    std::cout << " - 1 : x = " << a.x << " y = " << a.y << '\n';
    std::cout << " - 2 : x = " << b.x << " y = " << b.y << '\n';
    std::cout << " - 3 : x = " << c.x << " y = " << c.y << '\n';
    std::cout << "Площадь фигуры равна " << this->square() << '\n';
    std::cout << "Периметр нашей фигуры равен " << this->perimeter() << '\n';
    std::cout << "А вот и масса " << this->mass() << '\n';
    std::cout << "Теперь центр тяжести, вектор с координатами x = " << this->position().x << " y = " << this->position().y << '\n';
    std::cout << '\n';
}

void Rectangle::initFromDialog()
{
    std::cout << "Сейчас будем инициализировать прямоугольник\n";
    std::cout << "Нужно ввести координаты 3 точек, начнём\n";
    bool res = true;
    while(res)
    {
        try
        {
            std::cout << "Введите координаты первой точки\n";
            std::cin >> a.x >> a.y;
            std::cout << "Введите координаты второй точки (противоположная первой)\nИ да это принципиально\n";
            std::cin >> b.x >> b.y;
            std::cout << "Введите координаты третьей точки (любая из двух оставщихся)\n";
            std::cin >> c.x >> c.y;
            if(int(pow(dist(a, b), 2)) != int((pow(dist(a, c), 2) + pow(dist(b, c), 2))))
            {
                //std::cout << "NO\n";
                throw 1;
            }
            else
            {
                res = false;
            }
        }
        catch(int a)
        {
            std::cout << "Что-то пошло не по плану\n";
            if(a == 1)
            {
                std::cout << "Не корректная точка № 3, это не прямоугольник, простите\n";
            }
            std::cout << "Вам придется еще раз ввести координаты\n";
        }
    }
    std::cout << "Ура, мы почти создали прямоугольник\n";
    std::cout << "Теперь нужно ввести погонную площадь\n";
    res = true;
    while(res)
    {
        try
        {
            std::cin >> linear_area;
            res = false;
        }
        catch (int a)
        {
            std::cout << "Что-то пошло не по плану\n";
            std::cout << "Попробуйте еще раз\n";
        }
    }
    std::cout << "Ура, мы создали прямоугольник\n";
    std::cout << '\n';
}

const std::string Rectangle::classname()
{
    return(this->name);
}

unsigned int Rectangle::size()
{
    return(int(sizeof(*this)));
}

double Trapeze::dist(point point_1, point point_2)
{
    double a1 = (point_1.x - point_2.x)*(point_1.x - point_2.x);
    double a2 = (point_1.y - point_2.y)*(point_1.y - point_2.y);
    return(sqrt(a1 + a2));
}

double Trapeze::square()
{
    double ab = dist(a, b);
    double bc = dist(b, c);
    double cd = dist(c, d);
    double ad = dist(a, d);
    return ((bc + ad) / 2)*pow(ab*ab - (pow(ad - bc, 2) + ab*ab - cd*cd)/(2*(ad - bc)), 0.5);
}

double Trapeze::perimeter()
{
    double ab = dist(a, b);
    double bc = dist(b, c);
    double cd = dist(c, d);
    double ad = dist(a, d);
    return (ab + bc + cd + ad);
}

double Trapeze::mass()
{
    return this->square()*linear_area;
}

CVector2D Trapeze::position()
{
    point p1((b.x + c.x)/2, (b.y + c.y)/2);
    point p2((a.x + d.x)/2, (a.y + d.y)/2);
    return CVector2D((p1.x + p2.x)/2, (p1.y + p2.y)/2);
}

bool Trapeze::operator == (IPhysObject& obj)
{
    if(mass() == obj.mass())
    {
        return true;
    }
    return false;
}

bool Trapeze::operator < (IPhysObject& obj)
{
    if(this->mass() < obj.mass())
    {
        return true;
    }
    return false;
}

void Trapeze::draw()
{
    std::cout << "Координаты точек\n";
    std::cout << " - 1 : x = " << a.x << " y = " << a.y << '\n';
    std::cout << " - 2 : x = " << b.x << " y = " << b.y << '\n';
    std::cout << " - 3 : x = " << c.x << " y = " << c.y << '\n';
    std::cout << " - 4 : x = " << d.x << " y = " << d.y << '\n';
    std::cout << "Площадь фигуры равна " << this->square() << '\n';
    std::cout << "Периметр нашей фигуры равен " << this->perimeter() << '\n';
    std::cout << "А вот и масса " << this->mass() << '\n';
    std::cout << "Теперь центр тяжести, вектор с координатами x = " << this->position().x << " y = " << this->position().y << '\n';
    std::cout << '\n';
}

void Trapeze::initFromDialog()
{
    std::cout << "Сейчас будем инициализировать трапецию\n";
    std::cout << "Нужно ввести координаты 4 точек, начнём\n";
    bool res = true;
    while(res)
    {
        try
        {
            std::cout << "Введите координаты первой точки (левая точка нижнего основания)\n";
            std::cin >> a.x >> a.y;
            std::cout << "Введите координаты второй точки (левая точка верхнего основания)\n";
            std::cin >> b.x >> b.y;
            std::cout << "Введите координаты третьей точки (правая точка верхнего основания)\n";
            std::cin >> c.x >> c.y;
            std::cout << "Введите координаты четвертой точки (правая точка нижнего основания)\n";
            std::cin >> d.x >> d.y;
            res = false;
        }
        catch(int a)
        {
            std::cout << "Что-то пошло не по плану\n";
            std::cout << "Вам придется еще раз ввести координаты\n";
        }
    }
    std::cout << "Ура, мы почти создали трапецию\n";
    std::cout << "Теперь нужно ввести погонную площадь\n";
    res = true;
    while(res)
    {
        try
        {
            std::cin >> linear_area;
            res = false;
        }
        catch (int a)
        {
            std::cout << "Что-то пошло не по плану\n";
            std::cout << "Попробуйте еще раз\n";
        }
    }
    std::cout << "Ура, мы создали трапецию\n";
    std::cout << '\n';
}

const std::string Trapeze::classname()
{
    return(this->name);
}

unsigned int Trapeze::size()
{
    return(int(sizeof(*this)));
}