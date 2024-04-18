#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/segment/RangeAssignSegmentTree.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, q; scan >> n >> q;
    vector<pair<mint, mint>> a(n); scan >> a;
    RangeAssignSegmentTree<Monoid::Composite<mint>> seg(a);
    rep (q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r;
            mint b, c;
            scan >> l >> r >> b >> c;
            seg.set(l, r, {b, c});
        }
        else {
            int l, r, x;
            scan >> l >> r >> x;
            auto [b, c] = seg.prod(l, r);
            prints(b * x + c);
        }
    }
}
