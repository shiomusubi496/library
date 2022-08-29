#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_B"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/Dijkstra.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<int> G(N);
    rep (N) {
        int v, k; scan >> v >> k;
        G[v].reserve(k);
        rep (k) {
            int u, c; scan >> u >> c;
            G.add_edge(v, u, c, true);
        }
    }
    auto v = Dijkstra(G);
    rep (i, N) {
        print << i << ' ' << v[i] << endl;
    }
}
