#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int number_of_test_bits(int l)
{
    int k = 2;
    auto l2n = ::log10(2);
    while (k * l2n < ::log10(k + l + 1)) {
        k++;
    }
    return k;
}

int is_power_of_two(int x)
{
    return x && !(x & (x - 1));
}

bool is_there_a_mistake(int q, int l, string x)
{
    int p = 0, k;
    for(int j = q - 1; j <= l; j = k + q)
    {
        for(k = j; k < j + q && k <= l; k++)
        {
            if(x[k] == '1')
                p++;
        }
    }
    if(p % 2 == 0)
        return false;
    else
        return true;
}

int main()
{
    int n;
    cin >> n;
    string arr[n];
    for (int l = 0; l < n; l++)
    {
        cin >> arr[l];
    }
    for (int e = 0; e < n; e++)
    {
        int i = 0;
        int counter = 0;
        int k = number_of_test_bits(arr[e].length());
        while (i < k) {
            for (int j = 0; j < arr[e].length(); j++) {
                int q = j + 1;
                if (is_power_of_two(j + 1) == 0) {
                    i++;
                    if (is_there_a_mistake(q, arr[e].length(), arr[e]) == 1) {
                        counter += q;
                    }
                }
            }
        }
        if (counter != 0) {
            if (arr[e][counter - 1] == '1') {
                arr[e][counter - 1] = '0';
            } else {
                arr[e][counter - 1] = '1';
            }
        }
        for (int l = 0; l < arr[e].length(); l++) {
            if (is_power_of_two(l + 1) == 0) {
                cout << arr[e][l];
            }
        }
        cout << "\n";
    }
    return 0;
}