#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/DirectedMST.hpp"
using namespace std;
int main() {
    int N, M, S; scan >> N >> M >> S;
    Edges<ll> E(M);
    rep (i, M) {
        int a, b, c; scan >> a >> b >> c;
        E[i] = {a, b, c, i};
    }
    DirectedMST mst(N, E, S);
    assert(mst.has_mst());
    vector<int> par(N, S);
    for (auto e : mst.edges()) par[e.to] = e.from;
    prints(mst.cost());
    prints(par);
}
