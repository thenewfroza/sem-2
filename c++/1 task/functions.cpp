
#include "functions.h"
#include <iostream>
#include <cmath>
using namespace std;

void pFloat(float* pa){
    *pa = std::floor(*pa);
}

void aFloat(float &a){
    a = floor( a);
}


void pInverse(float* pa){
    *pa = 1 / *pa;
}

void aInverse(float &a){
    a = 1 / a;
}


void pCircle(struct circle* pf, float xr, float xy){
    pf->x = pf->x + xr;
    pf->y = pf->y + xy;
}

void aCircle(struct circle &f, float xr, float xy){
     f.x += xr;
     f.y += xy;
}


void pMatrix(matrix* pmtrx, float x){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            (*pmtrx).a[i][j] = (*pmtrx).a[i][j] * x;
        }
    }
}

void aMatrix(matrix &mtrx, float x){
    for(int i = 0; i < mtrx.n; i++){
        for(int j = 0; j < mtrx.m; j++){
            mtrx.a[i][j] = mtrx.a[i][j] * x;
        }
    }
}
