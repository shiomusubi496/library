#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/segment/DynamicSegmentTree.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, Q; scan >> N >> Q;
    DynamicSegmentTree<Monoid::Composite<mint>> seg(N);
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int k; scan >> k;
            mint a, b; scan >> a >> b;
            seg.set(k, {a, b});
        }
        else {
            int l, r; scan >> l >> r;
            mint x; scan >> x;
            auto [a, b] = seg.prod(l, r);
            prints(a * x + b);
        }
    }
}

