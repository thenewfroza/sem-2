#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector <bool> visited;
vector <vector<int>> g;
vector <int> dist;

void create_graph(int n, int m) {
    g.resize(n);
    visited.resize(n);
    dist.resize(n);
    fill(dist.begin(), dist.end(), -1);
    std::fill(visited.begin(), visited.end(), 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
}

void bfs(int v) {
    queue <int> q;
    q.push(v);
    visited[v] = true;
    dist[v] = 0;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < g[temp].size(); ++i) {
            int next = g[temp][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                dist[next] = dist[temp] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    create_graph(n,m);
    int s, f;
    cin >> s >> f;
    bfs(s-1);
    for
        std::cout << dist[f-1] << ' ';
    return 0;
}