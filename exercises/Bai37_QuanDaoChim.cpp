// exercises/Bai37_QuanDaoChim.cpp
#include "Graph.h"

int main() {
    cout << "--- BAI 37: QUAN DAO CHIM (TIM DINH TRU) ---\n";
    int n = 6;
    vector<pair<int, int>> edges = {
        {1,3}, {6,1}, {6,3}, {4,1},
        {6,4}, {5,2}, {3,2}, {3,5}
    };

    Graph g(n, false);
    for (auto p : edges) g.addEdge(p.first, p.second);

    vector<int> aps = g.findArticulationPoints();
    cout << "So dao gay ngat ket noi: " << aps.size() << endl; // Output: 1
    return 0;
}