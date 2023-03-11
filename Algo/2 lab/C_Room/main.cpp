#include<iostream>
#include<vector>

using namespace std;

vector<int> comp;
vector<pair<int, int>> visited;
vector<vector<int>> g;

void create_graph(int n, int m) {
    g.resize(n * m);
    visited.resize(n * m);
    char arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#'){
                visited[i * m + j].first = -1;
                visited[i * m + j].second = -1;
                continue;
            }
            if (arr[i][j] == '.' && arr[i - 1][j] == '.') {
                g[i * m + j].push_back((i - 1) * m + j);
            }
            if (arr[i][j] == '.' && arr[i][j - 1] == '.') {
                g[i * m + j].push_back(i * m + j - 1);
            }
            if (arr[i][j] == '.' && arr[i][j + 1] == '.') {
                g[i * m + j].push_back(i * m + j + 1);
            }

            if (arr[i][j] == '.' && arr[i + 1][j] == '.') {
                g[i * m + j].push_back((i + 1) * m + j);
            }
            visited[i * m + j].first = 0;
            visited[i * m + j].second = 1;
//            cout << i * m + j;
//            for(int k = 0; k < g[i * m + j].size(); k++){
//                cout << g[i * m + j][k] << ' ';
//            }
//            cout << endl;
        }
    }
//    for (int i = 0; i < g.size(); i++) {
//        for (int j = 0; j < g[i].size(); j++) {
//            cout << i << ' ' << g[i][j] << ' ';
//        }
//        cout << '\n';
//    }
}

void dfs(int v) {
    comp.push_back(v);
    visited[v].first = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int next = g[v][i];
        if (!visited[next].first)
            dfs(next);
    }
}

int findComps() {
    int res = 0;
//    for (int i = 0; i < visited.size(); i++) {
//        visited[i].first = 0;
//        visited[i].second = 1;
//    }
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i].first == 0) {
            ++res;
            comp.clear();
            dfs(i);
            for (int j = 0; j < comp.size(); j++)
                visited[comp[j]].second = res;
        }
    }
    return res;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    create_graph(n, m);
//    for (int i = 0; i < n * m; i++) {
//        std::cout << visited[i].first << ' ';
//    }
    std::cout << findComps() << endl;
//    for (int i = 0; i < n * m; i++) {
//        std::cout << visited[i].second << ' ';
//    }
    return 0;
}