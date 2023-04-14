#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>

const int INF = std::numeric_limits<int>::max();

struct edge {
    int from, to;
    int64_t weight;
};


void Bellman_Ford(const std::vector<edge> &g, std::vector<int64_t> &d, std::vector<int> &p,
                  std::vector<int> &cyrcle, int s) {
    d[s] = 0;
    int x;
    for (int i = 0; i < 3; ++i) {
        x = -1;
        for (auto e: g) {
            if (d[e.from] < INF) {
                if (d[e.to] > d[e.from] + e.weight) {
                    d[e.to] = d[e.from] + e.weight;
                    p[e.to] = e.from;
                    x = e.to;
                }
            }
        }
    }
    if (x != -1) {
        for (int i = 0; i < d.size(); ++i)
            x = p[x];
        cyrcle.push_back(x);
        for (int v = p[x]; v != x; v = p[v]) {
            cyrcle.push_back(v);
        }
        cyrcle.push_back(x);
        std::reverse(cyrcle.begin(), cyrcle.end());
    }
}

int main() {
    int N, k;
    int n, m;
    std::cin >> N >> k;
    std::vector<edge> g;
    std::vector<int> p(n);
    for (int i = 0; i < N; ++i) {
        std::cin >> n >> m;
        std::vector<int64_t> d(n);
        for (int j = 0; j < m; ++j) {
            int from, to, weight;
            std::cin >> from >> to >> weight;
            g.push_back({--from, --to, weight});
        }
        std::fill(d.begin(), d.end(), INF);
        std::fill(p.begin(), p.end(), -1);
        std::vector<int> cyrcle;
        Bellman_Ford(g, d, p, cyrcle, 0);
        for (int j = 0; j < cyrcle.size(); ++j) {
            std::cout << cyrcle[i];
        }
        if (cyrcle.size() < k + 1)
            std::cout << "YES" << std::endl;
        else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}