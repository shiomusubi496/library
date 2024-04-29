#define PROBLEM "https://judge.yosupo.jp/problem/vertex_get_range_contour_add_on_tree"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/RAQBIT.hpp"
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
    vector<RAQBIT<ll>> bit;
    ContourQuery cq(G, [&](auto v) {
        rep (i, v.size()) bit.emplace_back(v[i].size());
    });
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int p, l, r, x; scan >> p >> l >> r >> x;
            cq.range_contour(p, l, r, [&](int p, int r) { bit[p].add(0, r, x); }, [&](int p, int r) { bit[p].add(0, r, -x); });
        }
        else {
            int p; scan >> p;
            ll ans = A[p];
            cq.vertex(p, [&](int p, int k) { ans += bit[p].get(k); });
            prints(ans);
        }
    }
}
