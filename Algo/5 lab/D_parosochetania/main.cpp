#include <iostream>
#include <vector>

using namespace std;

bool Kuhn(int v, vector<vector<int>>& graph, vector<int>& match, vector<bool>& used) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int to : graph[v]) {
        if (match[to] == -1 || Kuhn(match[to], graph, match, used)) {
            match[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<bool>> block(N, vector<bool>(M));
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        block[x-1][y-1] = true;

    }
    vector<vector<int>> graph(N*M);
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (block[x][y]) {
                continue;
            }
            int from = x*M + y;
            for (auto d : direction) {
                int nx = x+d[0], ny = y+d[1];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M || block[nx][ny]) {
                    continue;
                }
                int to = nx*M + ny;
                graph[from].push_back(to);
            }
        }
    }
    vector<int> match(N*M, -1);
    vector<bool> used(N*M);
    for (int i = 0; i < N*M; i++) {
        fill(used.begin(), used.end(), false);
        Kuhn(i, graph, match, used);
    }
    int res = 0;
    for (int m : match) {
        if (m != -1) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}