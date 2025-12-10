// exercises/Bai41_SuaDuong.cpp
#include "Graph.h"

int main() {
    cout << "--- BAI 41: SUA DUONG (MST KRUSKAL) ---\n";
    int n = 5;
    Graph g(n, false);
    // Input mau: 5 dinh, 6 canh
    g.addEdge(1, 2, 3); g.addEdge(2, 3, 5); g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 8); g.addEdge(5, 1, 7); g.addEdge(5, 4, 4);

    long long cost = g.Kruskal();

    if (cost == -1) cout << "IMPOSSIBLE (Khong the ket noi het)" << endl;
    else cout << "Chi phi sua duong toi thieu: " << cost << endl; // Output: 14
    return 0;
}