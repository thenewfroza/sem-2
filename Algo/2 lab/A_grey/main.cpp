#include <iostream>
#include <vector>
#include <math.h>

std::vector<std::vector<int>> buildCode(int n, std::vector<std::vector<int>> &GrayCode) {
    // Построение кода длины 1
    int p = 2;
    for (int i = 1; i < n; i++) {
        int t = p;
        p = p * 2;
        for (int k = (p / 2) - 1; k < p; k++) {
            GrayCode[k] = GrayCode[t]     ;   // Отражение имеющихся кодов
            GrayCode[t][n - i - 1] = 0;
            GrayCode[k][n - i - 1] = 1 ;   // Добавление 0 и 1 в начало
            t--;
        }
    }
    return GrayCode;
};

int main() {
    int n;
    std::cin >> n;
    int k = pow(2, n);
    std::vector<std::vector<int>> arr(k);
    for (int i = 0; i < arr.size(); i++) {
        arr[i].resize(n);
    }
    arr[0][n-1] = 0;
    arr[1][n-1] = 1;
    buildCode(n, arr);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}