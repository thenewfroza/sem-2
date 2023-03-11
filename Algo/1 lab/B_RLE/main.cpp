#include <iostream>
#include<cctype>
#include<cmath>
#include<string>
using namespace std;

int number(char *arr, int i) {
    int k = 0;
    string y;
    while (isdigit(arr[i])) {
        y.push_back(arr[i]);
        i++;
        k++;
    }
    return stoi(y);
}

int len(int n) {
    double z = n;
    z = (int)(log10(z) + 1);
    return z;
}

int difference(int&x, int&y, char a, char b) {
    int counter = 0;
    if (a != b) {
        counter += min(x, y);
    }
    if (max(x,y) == x) {
        x -= y;
        y = 0;
    }
    else {
        y -= x;
        x = 0;
    }
    return counter;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    char Sasha[n], Masha[m];
    for (int i = 0; i < n; i++) {
        cin >> Sasha[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> Masha[i];
    }
    
    int i = 0, j = 0;
    int counter = 0;

    pair<int,char> sasha, masha;
    sasha.first = 0;
    masha.first = 0;
    
    while ((i < n || j < m) && counter < k) {
        if (i < n && j < m) {
            if (sasha.first == 0 && masha.first == 0) {
                sasha.second = Sasha[i];
                masha.second = Masha[j];
                sasha.first = number(Sasha, ++i);
                masha.first = number(Masha, ++j);
                i += len(sasha.first);
                j += len(masha.first);
                counter += difference(sasha.first, masha.first, sasha.second, masha.second);
            }
            else if (sasha.first != 0 && masha.first == 0) {
                masha.second = Masha[j];
                masha.first = number(Masha, ++j);
                j += len(masha.first);
                counter += difference(sasha.first, masha.first, sasha.second, masha.second);
            }
            else if (sasha.first == 0 && masha.first != 0) {
                sasha.second = Sasha[i];
                sasha.first = number(Sasha, ++i);
                i += len(sasha.first);
                counter += difference(sasha.first, masha.first, sasha.second, masha.second);
            }
        }
        else if (i == n && j < m) {
            while (j < m) {
                masha.second = Masha[j];
                masha.first = number(Masha, ++j);
                j += len(masha.first);
                counter += difference(sasha.first, masha.first, sasha.second, masha.second);
            }
        }
        else {
            while (i < n) {
                sasha.second = Sasha[i];
                sasha.first = number(Sasha, ++i);
                i += len(sasha.first);
                counter += difference(sasha.first, masha.first, sasha.second, masha.second);
            }
        }
    }
    if (counter > k) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
    return 0;
}