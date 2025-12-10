#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "DSU.h"

using namespace std;

// FIX LOI C4244: Khai bao so nguyen tuong minh
const long long INF = 1000000000000000000LL;

struct Edge {
    int u, v;
    long long w;
};

class Graph {
public:
    int n;
    bool directed;
    vector<vector<pair<int, long long>>> adj;
    vector<Edge> edges;

public:
    Graph(int nodes, bool isDirected = false) : n(nodes), directed(isDirected) {
        adj.resize(n + 1);
    }

    void addEdge(int u, int v, long long w = 1) {
        adj[u].push_back({ v, w });
        edges.push_back({ u, v, w });
        if (!directed) {
            adj[v].push_back({ u, w });
            edges.push_back({ v, u, w });
        }
    }

    // --- Cac ham tra ve du lieu ---
    vector<long long> Dijkstra(int start);
    bool hasNegativeCycle(); // Bellman-Ford
    vector<int> findArticulationPoints(); // Tarjan
    long long Kruskal(); // MST
    vector<int> getComponentSizes(); // BFS
};