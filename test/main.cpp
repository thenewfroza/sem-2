#include <bits/stdc++.h>

using namespace std;
vector<char> color;
vector<vector<int>> neighbours;

void dfs(int v, int p) {
    color[v] = 'g';
    for (int i = 0; i < neighbours[v].size(); i++) {

        if (i == p)
        if (color[neighbours[v][i]] == 'w') {
            dfs(i, v);
        } else if (color[neighbours[v][i]] == 'g') {
            cout << "YES";
            exit(0);
        }
    }
    color[v] = 'b';
}

int main() {

    int N , M;
    cin >> N >> M;

    color.resize(N);
    neighbours.resize(N);

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        neighbours[x - 1].push_back(y - 1);
        neighbours[y - 1].push_back(x - 1);
    }

    for (int i = 0; i < N; i++)
    {
        color[i] = 'w';
    }
    for (int i = 0; i < N; i++) {
        if (color[i] == 'w') {
            dfs(i, i);
        }
    }

    cout << "NO";
    return 0;
}