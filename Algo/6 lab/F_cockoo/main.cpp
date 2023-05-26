#include<bits/stdc++.h>

using namespace std;

struct key {
    string str;
    bool flag{};
    bool flagTemp{};
};


size_t hashMy(int function, std::string key, int m) {
    if (function == 1) {
        int p = 193;
        unsigned int hasH = 0;
        for (int i = 0; i < key.size(); ++i) {
            hasH += (size_t)(key[i]) * pow(p,i);
        }
        return hasH % m;
    }
    if (function == 2) {
        int p = 101;
        unsigned int hasH = 0;
        for (int i = 0; i < key.size(); ++i) {
            hasH += (key[i] - 'a' + 1) * pow(p,i);
        }
        return hasH % m;
    }
    return -1;
}

bool cuckoo(const string &key, struct key *table, int m) {
    int count{};
    int i = hashMy(1, key, m);
    int j;
    while (count < 1) {
        if (!table[i].flag) {
            table[i].str = key;
            table[i].flag = true;
            return true;
        }
        j = hashMy(2, key, m);
        if (!table[j].flag) {
            table[j].str = table[i].str;
            table[j].str = key;
            table[j].flag = true;
            return true;
        }
        i = hashMy(1, table[j].str, m);
        if (!table[i].flag) {
            table[i].str = table[j].str;
            table[i].str = key;
            table[i].flag = true;
            return true;
        }
        ++count;
    }
    return false;
}

bool find(const string &key, struct key *table, int m) {
    int i = hashMy(1, key, m);
    int j = hashMy(2, key, m);
    if (table[i].str == key) {
        return true;
    }
    if (table[j].str == key) {
        return true;
    }
    return false;
}

bool find3(const string &key, struct key *table, int m) {
    int i = hashMy(1, key, m);
    int j = hashMy(2, key, m);
    if (table[i].str == key) {
        table[i].flagTemp = true;
        return true;
    }
    if (table[j].str == key) {
        table[j].flagTemp = true;
        return true;
    }
    return false;
}

bool find3else(const string &key, struct key *table, int m) {
    int i = hashMy(1, key, m);
    int j = hashMy(2, key, m);
    if (table[i].str == key) {
        if (table[i].flagTemp) {
            return false;
        }
        return true;
    }
    if (table[j].str == key) {
        if (table[j].flagTemp) {
            return false;
        }
        return true;
    }
    return false;
}


int main() {

    int n;
    cin >> n;
    int m = 17*n;
    int ans[3]{0};

    key *hashTable = 0;
    key *hashTable1 = 0;
    hashTable = new key[m];
    hashTable1 = new key[m];
    string arr1[n];
    string arr2[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
        cuckoo(arr1[i], hashTable, m);
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
        cuckoo(arr2[i], hashTable1, m);
    }
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        if (find3(str, hashTable, m)) {
            if (!find3(str, hashTable1, m)) {
                ans[0] += 1;
                ans[2] += 1;
            }
        } else if (find3(str, hashTable1, m)) {
            ans[1] += 1;
            ans[2] += 1;
        } else {
            ans[2] += 3;
        }
    }

    for (int i = 0; i < n; ++i) {
        int c{};
        if (find(arr1[i], hashTable1, m)) {
            c++;
        }
        if (find3else(arr1[i], hashTable, m)) {
            if (c == 1) {
                ans[0] += 1;
            } else if (c == 0) {
                ans[0] += 3;
            }
        }
        c = 0;
        if (find(arr2[i], hashTable, m)) {
            c++;
        }
        if (find3else(arr2[i], hashTable1, m)) {
            if (c == 1) {
                ans[1] += 1;
            } else if (c == 0) {
                ans[1] += 3;
            }
        }
    }
    for (int an : ans) {
        cout << an << ' ';
    }
    return 0;
}
