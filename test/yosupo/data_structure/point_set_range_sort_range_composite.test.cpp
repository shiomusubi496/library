#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/segment/RangeSortQuery.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, q; scan >> n >> q;
    vector<ll> p(n);
    vector<pair<mint, mint>> a(n);
    rep (i, n) scan >> p[i] >> a[i];
    RangeSortQuery<Monoid::Composite<mint>> seg(a, p, 1e9);
    rep (q) {
        int t; scan >> t;
        if (t == 0) {
            int i, p; scan >> i >> p;
            mint a, b; scan >> a >> b;
            seg.set(i, p, {a, b});
        }
        else if (t == 1) {
            int l, r; scan >> l >> r;
            mint x; scan >> x;
            auto [a, b] = seg.prod(l, r);
            prints(a * x + b);
        }
        else if (t == 2) {
            int l, r; scan >> l >> r;
            seg.sort(l, r);
        }
        else {
            int l, r; scan >> l >> r;
            seg.sort(l, r, true);
        }
        // seg.debug();
    }
}
