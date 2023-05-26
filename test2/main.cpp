#include<bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> bildZ (string s){
    vector<int> z(s.size(), 0); int l = -1,r = -1; z[0] = s.size();
    for (int i = 1; i < s.size(); ++i) {
        z[i] = max(0, min(z[i - l], r - i - l));
        while (i + z[i] < s.size() && s[i+z[i]] == s[z[i]]);
        ++z[i];
        if (r < i + z[i]){
            r = i +z[i];
            l = i;
        }
    }
    return z;
}

int main() {
    string s = "abacababacb";
    vector<int> r = bildZ(s);
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << ' ';
    }
    return 0;
}
