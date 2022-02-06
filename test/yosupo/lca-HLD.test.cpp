#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../other/template.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/tree/HeavyLightDecomposition.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    UnweightedGraph G(N);
    reps (i, N - 1) {
        int p; cin >> p;
        G.add_edge(i, p);
    }
    HeavyLightDecomposition<unweighted_edge> HLD(G);
    rep (Q) {
        int a, b; cin >> a >> b;
        cout << HLD.lca(a, b) << endl;
    }
}
