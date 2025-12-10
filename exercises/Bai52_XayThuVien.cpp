// exercises/Bai52_XayThuVien.cpp
#include "Graph.h"

int main() {
    cout << "--- BAI 52: XAY DUNG THU VIEN ---\n";
    // Input mau 1: N=7, M=6, Build=3, Cost=2
    int n = 7;
    long long build = 3, cost = 2;

    Graph g(n, false);
    // Input mau noi 1-7 nhung co 8 dinh, gia su N=8 cho dung input
    g.addEdge(1, 2); g.addEdge(1, 3); g.addEdge(1, 7);
    g.addEdge(2, 3); g.addEdge(5, 6); g.addEdge(6, 8);

    // Hack nhe: do bai toan dung dinh 8, ta resize graph len 9
    g.n = 8; g.adj.resize(9);

    vector<int> components = g.getComponentSizes();
    long long totalCost = 0;

    for (int k : components) {
        // Cach 1: Xay thu vien cho moi thanh pho
        long long opt1 = k * build;
        // Cach 2: Xay 1 thu vien + sua (k-1) duong
        long long opt2 = build + (long long)(k - 1) * cost;
        totalCost += min(opt1, opt2);
    }

    cout << "Chi phi toi uu: " << totalCost << endl;
    return 0;
}