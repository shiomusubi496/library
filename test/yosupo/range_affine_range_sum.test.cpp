#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../other/template.hpp"
#include "../../math/ModInt.hpp"
#include "../../data-struct/segment/LazySegmentTree.hpp"
using namespace std;
using mint = modint998244353;
using PMM = pair<mint, mint>;
int main() {
    int N, Q; cin >> N >> Q;
    vector<mint> A(N); cin >> A;
    struct AffineSum {
        struct M {
            using value_type = mint;
            static mint op(mint a, mint b) { return a + b; };
            static mint id() { return 0; }
        };
        struct E {
            using value_type = PMM;
            static PMM op(PMM a, PMM b) { return PMM{a.first * b.first, a.second * b.first + b.second}; };
        };
        static mint op(PMM a, mint b) { return a.first * b + a.second; };
        static PMM mul(PMM a, int b) { return PMM{a.first, a.second * b}; };
    };
    MultiLazySegmentTree<AffineSum> seg(A);
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
