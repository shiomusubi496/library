#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/BinaryIndexedTree.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/ContourQuery.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    Graph<int> G(N);
    rep (N - 1) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    vector<BinaryIndexedTree<ll>> bit;
    ContourQuery cq(G, [&](auto v) {
        rep (i, v.size()) {
            vector<ll> B(v[i].size());
            rep (j, v[i].size()) B[j] = A[v[i][j]];
            bit.emplace_back(v[i].size());
            rep (j, v[i].size()) bit.back().add(j, B[j]);
        }
    });
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int p, x; scan >> p >> x;
            cq.vertex(p, [&](int a, int b) { bit[a].add(b, x); });
        }
        else {
            int p, l, r; scan >> p >> l >> r;
            ll ans = 0;
            cq.range_contour(p, l, r, [&](int p, int r) { ans += bit[p].sum(r); }, [&](int p, int r) { ans -= bit[p].sum(r); });
            prints(ans);
        }
    }
}
