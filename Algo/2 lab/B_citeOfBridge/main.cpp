#include<iostream>
#include<vector>

using namespace std;

std::vector<std::vector<int>> g;
std::vector<int> visited;
std::vector<int> p;

int start = -1, enD = -1;

void create_graph(int n, int m) {
    g.resize(n);
    visited.resize(n);
    p.resize(n);
    std::fill(p.begin(), p.end(), -1);
    std::fill(visited.begin(), visited.end(), 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }
}

bool dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int next = g[v][i];
        if (p[v] == next){
            continue;
        }

        if (visited[next] == 0) {
            p[next] = v;
            if (dfs(next))
                return true;
        }
        if (visited[next] == 1) {
            start = next;
            enD = v;
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

//int print_way(int v) {
//    if (v != start)
//        print_way(p[v]);
//    length++;
//    return  length;
//}

int main() {
    int n, m;
    cin >> n >> m;
    create_graph(n, m);

    for(int i = 0; (i < n) && !dfs(i); i++) {
    }
    if (start == -1)
        std::cout << "NO";
    else {
        cout << "YES\n";
    }
    return 0;
}