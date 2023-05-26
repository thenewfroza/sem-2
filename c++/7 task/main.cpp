#include<iostream>
#include <algorithm>
#include "CircularBuffer.h"
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    CircularBuffer<int> c(4);
    c.addFirst(1);
    c.addFirst(2);
    c.addFirst(4);
    c.addFirst(3);
    std::cout << c[0] << c[1] << c[2] << c[3] << endl;
    sort(c.begin(),c.end());
    c.addRandom(2,7);
    std::cout << c[0] << c[1] << c[2] << c[3];
}
