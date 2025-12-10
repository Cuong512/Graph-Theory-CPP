// exercises/Bai49_Neverland.cpp
#include "Graph.h"

int main() {
    cout << "--- BAI 49: NEVERLAND (DIJKSTRA PHAN TANG) ---\n";
    // Input mau: 10 dinh, 12 canh
    int n = 10;
    struct Inp { int u, v, w; };
    vector<Inp> inputs = {
        {1,2,4}, {5,7,1}, {4,6,4}, {7,9,3}, {9,10,1}, {7,8,5},
        {1,3,1}, {6,7,4}, {4,5,1}, {3,4,2}, {8,10,5}, {2,4,3}
    };

    // Tao do thi phan tang 2*N dinh (Tang 1: chua dung ve, Tang 2: da dung)
    Graph g(2 * n, true);

    for (auto& e : inputs) {
        g.addEdge(e.u, e.v, e.w);           // Di binh thuong o Tang 1
        g.addEdge(e.u + n, e.v + n, e.w);   // Di binh thuong o Tang 2
        g.addEdge(e.u, e.v + n, e.w / 2);   // Dung ve: chuyen tu Tang 1 -> Tang 2
    }

    vector<long long> d = g.Dijkstra(1);
    long long ans = min(d[n], d[2 * n]);

    cout << "Chi phi thap nhat: " << ans << endl; // Output: 7
    return 0;
}