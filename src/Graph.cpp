#include "Graph.h"

// 1. DIJKSTRA
vector<long long> Graph::Dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n + 1, INF);

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
    return dist;
}

// 2. BELLMAN-FORD
bool Graph::hasNegativeCycle() {
    vector<long long> d(n + 1, INF);
    // Bat dau tu dinh 1 (gia su do thi lien thong hoac co duong tu 1 den chu trinh)
    // De chat che hon co the them dinh ao noi voi tat ca, nhung voi bai tap co ban thi 1 la du
    d[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto& e : edges) {
            if (d[e.u] != INF && d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
            }
        }
    }
    for (auto& e : edges) {
        if (d[e.u] != INF && d[e.v] > d[e.u] + e.w) return true;
    }
    return false;
}

// 3. KRUSKAL
long long Graph::Kruskal() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
        });

    DSU dsu(n);
    long long mst_weight = 0;
    int count = 0;

    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            count++;
        }
    }
    if (count < n - 1) return -1;
    return mst_weight;
}

// 4. TARJAN (Dinh Tru)
namespace TarjanVars {
    int timer;
    vector<int> disc, low;
    vector<bool> isAP;

    void DFS_AP(int u, int p, const vector<vector<pair<int, long long>>>& adj) {
        int children = 0;
        disc[u] = low[u] = ++timer;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (v == p) continue;
            if (disc[v]) {
                low[u] = min(low[u], disc[v]);
            }
            else {
                children++;
                DFS_AP(v, u, adj);
                low[u] = min(low[u], low[v]);
                if (p != -1 && low[v] >= disc[u]) isAP[u] = true;
            }
        }
        if (p == -1 && children > 1) isAP[u] = true;
    }
}

vector<int> Graph::findArticulationPoints() {
    TarjanVars::timer = 0;
    TarjanVars::disc.assign(n + 1, 0);
    TarjanVars::low.assign(n + 1, 0);
    TarjanVars::isAP.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!TarjanVars::disc[i]) TarjanVars::DFS_AP(i, -1, adj);
    }

    vector<int> res;
    for (int i = 1; i <= n; i++) if (TarjanVars::isAP[i]) res.push_back(i);
    return res;
}

// 5. BFS (TPLT)
vector<int> Graph::getComponentSizes() {
    vector<bool> visited(n + 1, false);
    vector<int> sizes;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int count = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                count++;
                for (auto& edge : adj[u]) {
                    if (!visited[edge.first]) {
                        visited[edge.first] = true;
                        q.push(edge.first);
                    }
                }
            }
            sizes.push_back(count);
        }
    }
    return sizes;
}