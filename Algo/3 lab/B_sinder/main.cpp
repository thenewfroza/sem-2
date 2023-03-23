#include<iostream>
#include<vector>
#include<queue>

std::vector<std::vector<int>> g;
std::vector<char> visited;

void create_graph(int n, int m) {
    g.resize(n);
    visited.resize(n);
    std::fill(visited.begin(), visited.end(), 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
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
    int n, m, q;
    std::cin >> n >> m >> q;
    create_graph(n, m);
//    for (int i = 0; i < g.size(); i++){
//        for(int j = 0; j < g[i].size(); j++){
//            std::cout << g[i][j] + 1 << ' ';
//        }
//        std::cout << '\n';
//    }
    for (int i = 0; i < q; i++){
        std::fill(visited.begin(), visited.end(), 0);
        char x;
        int y, z;
        std::cin >> x >> y >> z;
        if (x == '?'){
            if(dfs(y - 1, z - 1) == 1){
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            std::erase(g[y - 1], z - 1);
            std::erase(g[z - 1], y - 1);
        }
    }
    return 0;
}
