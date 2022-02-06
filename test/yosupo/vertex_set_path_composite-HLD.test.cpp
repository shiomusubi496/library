#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../../other/template.hpp"
#include "../../data-struct/segment/SegmentTree.hpp"
#include "../../math/ModInt.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/tree/HeavyLightDecomposition.hpp"
using namespace std;
using mint = modint998244353;
using PMM = pair<mint, mint>;
int main() {
    int N, Q; cin >> N >> Q;
    vector<PMM> A(N); cin >> A;
    Graph<int> G(N);
    rep (N - 1) {
        int a, b; cin >> a >> b;
        G.add_edge(a, b);
    }
    HeavyLightDecomposition<int> HLD(G);
    struct Composite {
        using value_type = PMM;
        static PMM op(const PMM& a, const PMM& b) { return {a.first * b.first, a.second * b.first + b.second}; }
        static PMM id() { return {1, 0}; }
    };
    SegmentTree<Composite> seg(N);
    SegmentTree<Monoid::ReverseMonoid<Composite>> segrev(N);
    rep (i, N) {
        auto p = HLD.get_idx(i);
        seg.set(p.first, A[i]);
        segrev.set(p.first, A[i]);
    }
    rep (i, Q) {
        int t; cin >> t;
        if (t == 0) {
            int p; mint c, d; cin >> p >> c >> d;
            auto idx = HLD.get_idx(p);
            seg.set(idx.first, {c, d});
            segrev.set(idx.first, {c, d});
        }
        else {
            int u, v; mint x; cin >> u >> v >> x;
            HLD.each_vertex(
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
            cout << x << endl;
        }
    }
}
