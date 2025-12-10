#pragma once
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> sz; // Kich thuoc

public:
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;

        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }

    int getSize(int u) {
        return sz[find(u)];
    }
};