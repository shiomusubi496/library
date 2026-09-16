#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/segment/DynamicLazySegmentTree.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, Q; scan >> N >> Q;
    DynamicLazySegmentTree<Monoid::AffineSum<mint>> seg(N);
    rep (Q) {
        int t, l, r; scan >> t >> l >> r;
        if (t == 0) {
            mint a, b; scan >> a >> b;
            seg.apply(l, r, {a, b});
        }
        else {
            prints(seg.prod(l, r));
        }
    }
}
