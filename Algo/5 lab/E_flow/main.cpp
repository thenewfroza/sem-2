#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

bool bfs(std::vector<bool> & used, std::vector<int> & p, std::vector<std::vector<uint32_t>>& g) {
    int t = used.size() - 1;
    used[0] = true;
    p[0] = -1;
    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < used.size(); ++i) {
            int cap = g[u][i];
            if (cap != 0 && !used[i]) {
                used[i] = true;
                q.push(i);
                p[i] = u;
                if (i == t)
                    return true;
            }
        }
    }
    return false;
}

int min_path(std::vector<int> & p, std::vector<std::vector<uint32_t>>& g) {
    int min_p = 1000000;
    int v = p.size() - 1;
    while (p[v] != -1) {
        if (g[p[v]][v] < min_p)
            min_p = g[p[v]][v];
        v = p[v];
    }
    return min_p;
}

int main() {
    int n, m;
    std::vector<std::vector<uint32_t>> g;
    std::cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; ++i)
        g[i].resize(n, 0);

    for (int i = 0; i < m; ++i) {
        int from, to, cap;
        std::cin >> from >> to >> cap;
        g[from - 1][to - 1] += cap;
    }
    std::vector<bool> used(n, false);
    std::vector<int> p(n, -1);
    uint64_t max_flow = 0;
    while (bfs(used, p, g)) {
        int min_p = min_path(p, g);
        max_flow += min_p;
        int v = p.size() - 1;
        while (p[v] != -1) {
            g[p[v]][v] -= min_p;
            g[v][p[v]] += min_p;
            v = p[v];
        }
        p.assign(n, -1);
        used.assign(n, false);
    }
    std::cout << max_flow;
    return 0;
}