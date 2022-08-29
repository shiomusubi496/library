#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/segment/LazySegmentTree.hpp"
using namespace std;
using mint = modint998244353;
using PMM = pair<mint, mint>;
int main() {
    int N, Q; scan >> N >> Q;
    vector<mint> A(N); scan >> A;
    LazySegmentTree<Monoid::AffineSum<mint>> seg(A);
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r, b, c; scan >> l >> r >> b >> c;
            seg.apply(l, r, PMM{b, c});
        }
        else {
            int l, r; scan >> l >> r;
            print << seg.prod(l, r) << endl;
        }
    }
}
