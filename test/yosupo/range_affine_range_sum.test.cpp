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
    MultiLazySegmentTree<mint, PMM> seg(
        A,
        [](mint a, mint b) -> mint { return a + b; },
        mint{0},
        [](PMM a, mint b) -> mint { return a.first * b + a.second; },
        [](PMM a, PMM b) -> PMM { return PMM{a.first * b.first, a.first * b.second + a.second}; },
        [](PMM a, int b) -> PMM { return PMM{a.first, a.second * b}; }
    );
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
