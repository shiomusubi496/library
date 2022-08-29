#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/segment/SqrtDecomposition.hpp"
using namespace std;
using mint = modint998244353;
using PMM = pair<mint, mint>;
struct CompositeAction {
    using M = Monoid::Sum<mint>;
    using E = Monoid::Composite<mint>;
    static mint op(const PMM& a, const mint& b) {
        return a.first * b + a.second;
    }
};
int main() {
    int N, Q; scan >> N >> Q;
    vector<mint> A(N); scan >> A;
    auto f = [&](vector<mint>&& v) -> pair<mint, int> {
        mint ans = 0;
        each_const (i : v) ans += i;
        return {ans, v.size()};
    };
    auto g = [&](const PMM& x, pair<mint, int>& p) -> void {
        p.first = p.first * x.first + p.second * x.second;
    };
    SqrtDecomposition<mint, decltype(f), decltype(g), CompositeAction> seg(A, f, g);
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r, b, c; scan >> l >> r >> b >> c;
            seg.apply(l, r, PMM{b, c});
        }
        else {
            int l, r; scan >> l >> r;
            auto g = [&](const mint& x) -> mint {
                return x;
            };
            auto h = [&](const pair<mint, int>& p) -> mint {
                return p.first;
            };
            print << seg.prod<Monoid::Sum<mint>>(l, r, g, h) << endl;
        }
    }
}
