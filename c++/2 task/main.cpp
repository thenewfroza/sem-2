#include <iostream>
#include <cmath>

class Vector {
private:
    float x;
    float y;
    float z;

public:
    Vector();

    Vector(float _x, float _y, float _z);

    Vector(Vector &v);

    [[nodiscard]] float getX() const;

    [[nodiscard]] float getY() const;

    [[nodiscard]] float getZ() const;

    void getVector() const;

    [[nodiscard]] float lengthOfVector() const;

    float angleBetweenVectors(Vector &v) const;

    void sumOfVectors(Vector &v, Vector &v1);

};

Vector::Vector() {
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(float _x, float _y, float _z) {
    x = _x;
    y = _y;
    z = _z;
}

Vector::Vector(Vector &v) {
x = v.x;
y = v.y;
z = v.z;
}

float Vector::getX() const {
    return x;
}

[[nodiscard]] float Vector::getY() const {
    return y;
}

[[nodiscard]] float Vector::getZ() const {
    return z;
}

void Vector::getVector() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

[[nodiscard]] float Vector::lengthOfVector() const {
    float l;
    l = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    return l;
}

float Vector::angleBetweenVectors(Vector &v) const {
    float a;
    a = acos((this->x * v.x + this->y * v.y + this->z * v.z) /
             (sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)) *
              sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2))));
    return a;
}

void Vector::sumOfVectors(Vector &v, Vector &v1) {

    x = v.x + v1.x;
    y = v.y + v1.y;
    z = v.z + v1.z;

}

int main() {
    Vector vector{1, 2, 3};
    Vector vector1{3, 2, 0};
    Vector vector2;
    vector2.sumOfVectors(vector, vector1);
    vector2.getVector();
    std::cout << vector2.lengthOfVector() << std::endl;
    std::cout.precision(2);
    std::cout << vector2.angleBetweenVectors(vector1) << std::endl;
    return 0;
}
