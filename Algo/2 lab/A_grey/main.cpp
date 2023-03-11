#include <iostream>
#include <vector>
#include <math.h>

std::vector<std::string> buildCode(int n) {

    if (n == 0)
        return {"0"};
    std::vector<std::string> GrayCode;
    GrayCode.push_back("0");
    GrayCode.push_back("1");
    for (int i = 2; i < (1 << n); i = i << 1){
        for (int j = i-1 ; j >= 0 ; j--) {
            GrayCode.push_back(GrayCode[j]);
        }
        for (int j = 0; j < i; j++){
            GrayCode[j] = "0" + GrayCode[j];
        }
        for (int j = i; j < 2*i; j++){
            GrayCode[j] = "1" +  GrayCode[j];
        }
    }
    return GrayCode;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> GrayCode = buildCode(n);
    for (int i = 0; i < GrayCode.size(); i++) {
        std::cout << GrayCode[i] << std::endl;
    }
    return 0;
}