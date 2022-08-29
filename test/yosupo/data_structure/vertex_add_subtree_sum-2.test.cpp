#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/BinaryIndexedTree.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/EulerTourSubtree.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    Graph<int> G(N);
    rep (i, 1, N) {
        int p; scan >> p;
        G.add_edge(i, p);
    }
    EulerTourSubtree<int> ET(G);
    BinaryIndexedTree<ll> BIT(N);
    rep (i, N) {
        auto p = ET.get_idx(i);
        BIT.add(p.first, A[i]);
    }
    rep (i, Q) {
        int t; scan >> t;
        if (t == 0) {
            int p; ll x; scan >> p >> x;
            auto idx = ET.get_idx(p);
            BIT.add(idx.first, x);
        }
        else {
            int u; scan >> u;
            ll ans = 0;
            ET.each_vertex_subtree(u, [&](int l, int r) { ans += BIT.sum(l, r); });
            print << ans << endl;
        }
    }
}
