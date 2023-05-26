#include <iostream>
#include <vector>

int hash(int x) {
    return x % 1000003;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    std::vector<int> h(1000003, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        counter += h[hash(arr[i]) - i + 1000000];
        h[hash(arr[i] - i + 1000000)]++;
    }
    std::cout << counter;
    return 0;
}
