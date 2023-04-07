#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/segment/DualSegmentTree.hpp"
using namespace std;
using mint = modint998244353;
struct Action {
    using M = Monoid::Sum<mint>;
    using E = Monoid::Composite<mint>;
    static mint op(const pair<mint, mint>& a, const mint& b) {
        return a.first * b + a.second;
    }
};
int main() {
    int N, Q; scan >> N >> Q;
    vector<mint> A(N); scan >> A;
    DualSegmentTree<Action> seg(A);
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r; scan >> l >> r;
            mint a, b; scan >> a >> b;
            seg.apply(l, r, {a, b});
        }
        else {
            int k; scan >> k;
            print << seg.get(k) << endl;
        }
    }
}
