#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../other/template.hpp"
#include "../../other/monoid2.hpp"
#include "../../math/ModInt.hpp"
#include "../../data-struct/segment/LazySegmentTree.hpp"
using namespace std;
using mint = modint998244353;
using PMM = pair<mint, mint>;
int main() {
    int N, Q; cin >> N >> Q;
    vector<mint> A(N); cin >> A;
    LazySegmentTree<Monoid::AffineSum<mint>> seg(A);
    rep (Q) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, b, c; cin >> l >> r >> b >> c;
            seg.apply(l, r, PMM{b, c});
        }
        else {
            int l, r; cin >> l >> r;
            cout << seg.prod(l, r) << endl;
        }
    }
}
