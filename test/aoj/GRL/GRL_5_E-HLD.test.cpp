#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/LazySegmentTree.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/HeavyLightDecomposition.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    Graph<int> G(n);
    rep (i, n) {
        int k; scan >> k;
        rep (k) {
            int a; scan >> a;
            G.add_edge(i, a);
        }
    }
    HeavyLightDecomposition<int> HLD(G);
    RangeAddQueryRangeSumQuery<ll> seg(n);
    int q; scan >> q;
    rep (q) {
        int t; scan >> t;
        if (t == 0) {
            int v; ll w; scan >> v >> w;
            HLD.each_edge(0, v, [&](int l, int r) {
                seg.apply(l, r, w);
            });
        }
        else {
            int u; scan >> u;
            ll ans = 0;
            HLD.each_edge(0, u, [&](int l, int r) {
                ans += seg.prod(l, r);
            });
            print << ans << endl;
        }
    }
}
