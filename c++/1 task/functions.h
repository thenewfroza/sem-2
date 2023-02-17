//
// Created by thene on 17.02.2023.
//

#ifndef INC_1_TASK_FUNCTIONS_H
#define INC_1_TASK_FUNCTIONS_H

const int N = 3;

struct circle {
    float x;
    float y;
    float rad;
};

class matrix {
public:
    float **a;
    const int n = 3, m = 3;
    matrix() {
        a = new float*[n];
        for (int i = 0; i < n; ++i)
            a[i] = new float[m];
    }
    ~matrix() {
        for (int i = 0; i < n; ++i)
            delete[] a[i];
        delete[] a;
    }
};

void pFloat(float* pa);
void aFloat(float &a);

void pInverse(float* pa);
void aInverse(float &a);

void pCircle(struct circle* pf, float xr, float xy);
void aCircle(struct circle &f, float xr, float xy);

void pMatrix(struct matrix* pmtrx, float x);
void aMatrix(struct matrix &mtrx, float x);


#endif //INC_1_TASK_FUNCTIONS_H
