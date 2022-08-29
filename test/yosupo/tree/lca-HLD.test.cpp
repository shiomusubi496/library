#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/HeavyLightDecomposition.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    UnweightedGraph G(N);
    reps (i, N - 1) {
        int p; scan >> p;
        G.add_edge(i, p);
    }
    HeavyLightDecomposition<unweighted_edge> HLD(G);
    rep (Q) {
        int a, b; scan >> a >> b;
        print << HLD.lca(a, b) << endl;
    }
}
