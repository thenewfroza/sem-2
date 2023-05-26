#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;

struct student{
    int isu;
    int points;
};
struct group{
    int avg{};
    int MAX{};
    int size;
    vector<student> gr;
};

void insert(vector<group> &hashTable, int isu, int points, int hash){
    if (points > hashTable[hash].MAX){
        hashTable[hash].MAX = points;
    }
    hashTable[hash].avg += points;
    hashTable[hash].size++;
    hashTable[hash].gr.push_back({isu, points});
}

void del(vector<group> &hashTable, int isu, int hash){
    for (int i = 0; i < hashTable[hash].gr.size(); ++i) {
        if (hashTable[hash].gr[i].isu == isu){
            hashTable[hash].avg -= hashTable[hash].gr[i].points;
            hashTable[hash].gr.erase(hashTable[hash].gr.cbegin()+i);
        }
    }
    hashTable[hash].MAX = 0;
    hashTable[hash].size--;
}

int avg(vector<group> &hashTable,int hash){
    return hashTable[hash].avg / hashTable[hash].size;
}

int MAX(vector<group> &hashTable,int hash){
    for (int i = 0; i < hashTable[hash].gr.size(); ++i) {
        if (hashTable[hash].gr[i].points > hashTable[hash].MAX)
            hashTable[hash].MAX = hashTable[hash].gr[i].points;
    }
    return hashTable[hash].MAX;
}

int hasht(int x) {
    return x % 10003;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int m, q;
    cin >> m >> q;
    vector<group> hashTable(10003);
    for (int i = 0; i < q; ++i) {
        char com;
        cin >> com;
        if (com == '+') {
            int group, isu, points;
            cin >> group >> isu >> points;
            int h = hasht(group);
            insert(hashTable, isu, points, h);
        }
        if (com == 'm') {
            int group;
            cin >> group;
            int h = hasht(group);
            cout << MAX(hashTable, h) << '\n';
        }
        if (com == 'a') {
            int group;
            cin >> group;
            int h = hasht(group);
            cout << avg(hashTable, h) << '\n';
        }
        if (com == '-') {
            int group, isu;
            cin >> group >> isu;
            int h = hasht(group);
            del(hashTable, isu, h);
        }
    }
    return 0;
}
