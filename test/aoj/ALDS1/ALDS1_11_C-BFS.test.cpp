#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/BreadthFirstSearch.hpp"
using namespace std;
int main() {
    int N; cin >> N;
    Graph<int> G(N);
    rep (N) {
        int u; cin >> u;
        int k; cin >> k;
        rep (j, k) {
            int v; cin >> v;
            G.add_edge(u - 1 , v - 1 , true);
        }
    }
    vector<int> dist = BFS(G);
    rep (i, N) {
        cout << i + 1 << ' ' << dist[i] << endl;
    }
}
