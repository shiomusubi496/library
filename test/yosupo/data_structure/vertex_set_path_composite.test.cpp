#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../data-struct/segment/SegmentTree.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/EulerTour.hpp"
using namespace std;
using mint = modint998244353;
using PMM = pair<mint, mint>;
using M = Monoid::Composite<mint>;
int main() {
    int N, Q; scan >> N >> Q;
    vector<PMM> A(N); scan >> A;
    Graph<int> G(N);
    rep (N - 1) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    EulerTour<int> ET(G);
    SegmentTree<M> seg(2 * N);
    SegmentTree<Monoid::ReverseMonoid<M>> segrev(2 * N);
    rep (i, N) {
        auto p = ET.get_idx(i);
        seg.set(p.first, A[i]);
        seg.set(p.second, M::get_inv(A[i]));
        segrev.set(p.first, A[i]);
        segrev.set(p.second, M::get_inv(A[i]));
    }
    rep (i, Q) {
        int t; scan >> t;
        if (t == 0) {
            int p; mint c, d; scan >> p >> c >> d;
            auto idx = ET.get_idx(p);
            seg.set(idx.first, {c, d});
            seg.set(idx.second, M::get_inv({c, d}));
            segrev.set(idx.first, {c, d});
            segrev.set(idx.second, M::get_inv({c, d}));
        }
        else {
            int u, v; mint x; scan >> u >> v >> x;
            ET.each_vertex(
                u, v,
                [&](int l, int r) {
                    auto p = seg.prod(l, r);
                    x = p.first * x + p.second;
                },
                [&](int l, int r) {
                    auto p = segrev.prod(l, r);
                    x = p.first * x + p.second;
                }
            );
            print << x << endl;
        }
    }
}
