#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../../other/template.hpp"
#include "../../data-struct/segment/BinaryIndexedTree.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/tree/HeavyLightDecomposition.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N); cin >> A;
    Graph<int> G(N);
    rep (i, 1, N) {
        int p; cin >> p;
        G.add_edge(i, p);
    }
    HeavyLightDecomposition<int> HLD(G);
    BinaryIndexedTree<ll> BIT(N);
    rep (i, N) {
        auto p = HLD.get_idx(i);
        BIT.add(p.first, A[i]);
    }
    rep (i, Q) {
        int t; cin >> t;
        if (t == 0) {
            int p; ll x; cin >> p >> x;
            auto idx = HLD.get_idx(p);
            BIT.add(idx.first, x);
        }
        else {
            int u; cin >> u;
            ll ans = 0;
            HLD.each_vertex_subtree(u, [&](int l, int r) { ans += BIT.sum(l, r); });
            cout << ans << endl;
        }
    }
}
