// exercises/Bai53_SaoHoa.cpp
#include "Graph.h"

int main() {
    cout << "--- BAI 53: DUONG LEN SAO HOA ---\n";
    int n = 6; // 6 nguoi
    Graph g(n, false);
    // Input: Cung quoc gia (0,1), (1,2), (3,4) -> Doi sang 1-based: (1,2), (2,3), (4,5)
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    // Dinh 6 (so 5 cu) dung yen

    vector<int> sizes = g.getComponentSizes();

    long long totalPairs = (long long)n * (n - 1) / 2;
    long long sameCountryPairs = 0;

    for (int k : sizes) {
        sameCountryPairs += (long long)k * (k - 1) / 2;
    }

    cout << "So cach chon 2 nguoi khac quoc gia: " << totalPairs - sameCountryPairs << endl;
    // Output: 11
    return 0;
}