#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> g;
std::vector<int> visited;
std::vector<int> dist;

using namespace std;

void create_graph(int n, int m) {
    g.resize(n);
    visited.resize(n);
    dist.resize(n);
    fill(dist.begin(), dist.end(), INT64_MIN);
    std::fill(visited.begin(), visited.end(), 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
}

void dfs(int v, int d) {
    visited[v] += 1;
    dist[v] = ++d;
    for (int i = 0; i < g[v].size(); i++) {
        int next = g[v][i];
        if (visited[next] == 0)
            dfs(next, d);
    }
}

int main() {
    int d = 0;
    int n, m;
    cin >> n >> m;
    create_graph(n, m);
    dfs(0, d);

    int max = INT32_MIN;
    int iter = -1;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] > max) {
            max = dist[i];
            iter = i;
        }
    }

    std::fill(visited.begin(), visited.end(), 0);
    d = 0;
    dfs(iter, d);

    max = INT32_MIN;
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] > max)
            max = dist[i];
    }
    if (max == n) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}