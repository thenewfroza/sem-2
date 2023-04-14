#include<iostream>
#include<set>
#include<vector>
#include<limits>

const int64_t INF = std::numeric_limits<int64_t>::max();
typedef std::vector<std::vector<std::pair<int, int>>> GRAPH;

void dijkstra(const GRAPH &g, std::vector<int64_t> &d, int start) {
    d[start] = 0;
    std::set<std::pair<int64_t, int>> q;
    q.insert({0, 0});
    int v = start;
    bool f = 0;
    while (!q.empty()) {
        if (f == 1) {
            v = q.begin()->second;
        }
        q.erase(q.begin());
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i].first;
            int weight = g[v][i].second;
            if (d[to] > d[v] + weight) {
                q.erase({d[to], to});
                d[to] = d[v] + weight;
                q.insert({d[to], to});
            }
        }
        f = 1;
    }

    for (int i = 0; i < d.size(); ++i) {
        if (d[i] == 9223372036854775807)
            d[i] = -1;
    }
}

int main() {

    int n, m, s, f;
    std::cin >> n >> m >> s >> f;
    GRAPH g(n);
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        std::cin >> x >> y >> w;
        g[x - 1].push_back({y - 1, w});
    }
    std::vector<int64_t> d(n, INF);
    dijkstra(g, d, s - 1);
    std::cout << d[f - 1] << std::endl;


    return 0;
}