#include <iostream>
#include<vector>
#include<queue>
using namespace std;


std::vector<std::vector<int>> g;
std::vector<char> visited;
std::vector <int> dist;

void create_graph(int n, int m) {
    g.resize(n);
    dist.resize(n);
    visited.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        g[x - 1].push_back(y - 1);
    }
}

bool dfs(int start, int end){
    visited[start] = 1;
    if (start == end){
        return 1;
    }
    for (int i = 0; i < g[start].size(); i++){
        int next = g[start][i];
        if (!visited[next]){
            if (dfs(next,end)){
                return 1;
            }
        }
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, g;
    std::cin >> n >> m >> g;
    create_graph(n,m);
    for (int i = 0; i < g; i++) {
        int start, end;
        std::cin >> start >> end;
        bool a,b;

        std::fill(visited.begin(), visited.end(), 0);
        a = dfs(start - 1, end - 1);

        std::fill(visited.begin(), visited.end(), 0);
        b = dfs(end - 1, start - 1);

        if (a == 1 && b == 1) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    };
    return 0;
}
