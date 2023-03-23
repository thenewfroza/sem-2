#include<iostream>
#include<vector>

using namespace std;
struct Point3D{
    int first;
    int second;
    int third;
};

vector<int> comp;
vector<Point3D> visited;
vector<vector<int>> g;
vector<int> trap;

void create_graph(int n, int m) {
    g.resize(n);
    visited.resize(n);
    trap.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
        visited[x-1].first = 0;
        visited[y-1].first = 0;
        visited[x-1].second = 1;
        visited[y-1].second = 1;
    }
    for (int i = 0; i < trap.size(); i++){
        cin >> trap[i];
    }
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
    n = findComps();
    std::cout << n << endl;
    for (int i = 0; i < visited.size(); i++){
        cout << visited[i].second << ' ' ;
    }
    cout << endl;

//    for (int i = 0; i < n * m; i++) {
//        std::cout << visited[i].second << ' ';
//    }

    vector<int> ans;
    ans.resize(n);
    fill(ans.begin(), ans.end(), 0);

    for (int i = 0; i < trap.size(); i++){
        if (trap[i] > 0){
            ans[visited[i].second - 1] = trap[i];
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    return 0;
}