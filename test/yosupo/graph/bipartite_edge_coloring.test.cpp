#define PROBLEM "https://judge.yosupo.jp/problem/bipartite_edge_coloring"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/BipartiteEdgeColoring.hpp"
using namespace std;
int main() {
    int L, R, M; scan >> L >> R >> M;
    Edges<int> es(M);
    rep (i, M) scan >> es[i].from >> es[i].to;
    auto bec = BipartiteEdgeColoring<int>(L, R, es);
    prints(bec.edge_chromatic_number());
    rep (i, M) prints(bec[i]);
}
