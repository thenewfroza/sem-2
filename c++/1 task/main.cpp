#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    //1
    float a, ansa;
    cout << "Enter float number: ";
    cin >> a;
    cout << "Ender answer: ";
    cin >> ansa;
    pFloat(&a);
    if (a == ansa) {
        cout << "Yipee" << endl;
    }
    else {
        cout << "Oops( " << a << endl;
    }

    float b, ansb;
    cout << endl << "Enter float number: ";
    cin >> b;
    cout << "Ender answer: ";
    cin >> ansb;
    aFloat(b);
    if (b == ansb) {
        cout << "Yipee" << endl;
    }
    else {
        cout << "Oops(" << b << endl;
    }
    //2
    float c, ansc;
    cout << endl << "Enter float number: ";
    cin >> c;
    cout << endl << "Ender answer: ";
    cin >> ansc;
    pInverse(&c);
    if (c == ansc) {
        cout << "Yipee" << endl;
    }
    else {
        cout << "Oops(" << c << endl;
    }

    float d, ansd;
    cout << endl << "Enter float number: ";
    cin >> d;
    cout << endl << "Ender answer: ";
    cin >> ansd;
    aInverse(d);
    if (d == ansd) {
        cout << "Yipee" << endl;
    }
    else {
        cout << "Oops(" << d << endl;
    }

    //3
    cout << endl << "Enter middle point of circle: ";
    struct circle fig{}, f{};
    cin >> fig.x >> fig.y >> fig.rad;
    cout << "On which vector need to move: ";
    float xv, yv;
    cin >> xv >> yv;
    cout << endl << "Ender answer: ";
    cin >> f.x >> f.y;
    pCircle(&fig, xv, yv);
    if ((fig.x == f.x) && (fig.y == f.y)){
        cout << "Yipee" << endl;
    }
    else {
        cout << "Oops(" << endl;
    }

    cout << endl << "Enter middle point of circle:";
    struct circle fig2{}, f2{};
    cin >> fig2.x >> fig2.y >> fig2.rad;
    cout << "On which vector need to move: ";
    float xv2, yv2;
    cin >> xv2 >> yv2;
    cout << endl << "Ender answer: ";
    cin >> f.x >> f.y;
    aCircle(fig2, xv2, yv2);
    if ((fig2.x == f2.x) && (fig2.y == f2.y)){
        cout << "Yipee" << endl;
    }
    else {
        cout << "Oops(" << endl;
    }


    //4
    matrix arr;
    cout << "Enter matrix:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr.a[i][j];
    cout << "By what number do we multiply?: \n" << endl;
    float l1;
    cin >> l1;
    pMatrix(&arr, l1);
    int answ[3][3];
    int answer = 1;
    cout << "Ender answer:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            cin >> answ[i][j];
        }
    }
    for (int i = 0; i < arr.n; ++i){
        for (int j = 0; j < arr.m; ++j){
        cout << arr.a[i][j] << " ";
            if ((arr.a[i][j] == answ[i][j]) && (answer == 1)) {
                answer = 1;
            }
            else {
                answer = 0;
            }
        }
        cout << "\n";
    }
    if (answer == 1) {
        cout << "Yipee" << endl;
    }
    else {
        cout << "Oops(" << endl;
    }

    matrix arr2;
    cout << "Enter matrix:\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr2.a[i][j];
    cout << "By what number do we multiply?: \n" << endl;
    float l2;
    cin >> l2;
    aMatrix(arr2, l2);
    int answ2[3][3];
    int answer2 = 1;
    cout << "Ender answer:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            cin >> answ2[i][j];
        }
    }
    for (int i = 0; i < arr2.n; ++i){
        for (int j = 0; j < arr2.m; ++j){
            cout << arr2.a[i][j] << " ";
            if ((arr2.a[i][j] == answ2[i][j]) && (answer2 == 1)) {
                answer2 = 1;
            }
            else {
                answer2 = 0;
            }
        }
        cout << "\n";
    }
    if (answer2 == 1) {
        cout << "Yipee" << endl;
    }
    else {
        cout << "Oops(" << endl;
    }
    return 0;
}
