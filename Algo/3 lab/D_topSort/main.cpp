#include<iostream>
#include<vector>

std::vector<std::vector<int>> g;
std::vector<char> visited;
std::vector<int> sorted;
std::vector<int> ans;
int k;

void create_graph(int n, int m) {
    g.resize(n);
    visited.resize(n);
    ans.resize(n);
    std::fill(visited.begin(), visited.end(), 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }


}

void dfs(int v) {
    visited[v] = 1;
//    std::cout << "start " << v +1 << std::endl;
    for (int i = 0; i < g[v].size(); i++) {
        int next = g[v][i];
        if (visited[next] == 1) {
            std::cout << -1;
            exit(0);
        }
        if (visited[next] == 0)
            dfs(next);
    }
//    std::cout << "end " << v+1 <<  std::endl;
//    std::cout << v+1 << "=" << k <<  std::endl;
    visited[v] = 2;
    ans[v] = k--;
    sorted.push_back(v);
}

void topological_sort(int n, int m) {
    create_graph(n, m);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0)
            dfs(i);
    }
//    for (int i = 0; i < g.size(); i++) {
//        for (int j = 0; j < g[i].size(); j++) {
//            std::cout <<  ' ' << g[i][j]  << ' ';
//        }
//        std::cout << std::endl;
//    }
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << ' ';
}

int main() {
    int n, m;
    std::cin >> n >> m;
    k = n;
    topological_sort(n, m);
    return 0;
}
