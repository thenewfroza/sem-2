#include <iostream>
#include <vector>
#include <algorithm>


class DSU {
    int *parent;
    int *rank;
public:
    explicit DSU(int n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; ++i) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            } else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            } else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

void kruskal(std::vector<std::vector<int>> edge, int n) {
    std::sort(edge.begin(), edge.end());
    DSU s(n);
    int ans = 0;

    for (auto e: edge) {
        int w = e[0];
        int x = e[1];
        int y = e[2];

        if (s.find(x) != s.find(y)) {
            s.unite(x, y);
            ans += w;
        }
    }
    DSU c(n);
    std::cout << ans << ' ';
    ans = 0;
    std::sort(edge.begin(), edge.end());
    edge.erase(edge.cbegin()+2);
    for (auto e: edge) {
        int w = e[0];
        int x = e[1];
        int y = e[2];

        if (c.find(x) != c.find(y)) {
            c.unite(x, y);
            ans += w;
        }
    }
    std::cout << ans;
}

int main() {
    int n, m;
    std::vector<std::vector<int>> edge;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int to, from, weight;
        std::cin >> to >> from >> weight;
        edge.push_back({weight,--from,--to});
    }
    kruskal(edge, n);

    return 0;
}
