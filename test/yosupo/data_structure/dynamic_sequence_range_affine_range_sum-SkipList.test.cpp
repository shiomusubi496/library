#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/other/SkipList.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, Q; scan >> N >> Q;
    vector<mint> A(N); scan >> A;
    SkipList<Monoid::AffineSum<mint>> sl(A), slrev(vector<mint>(rall(A)));
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int k; scan >> k;
            mint x; scan >> x;
            sl.insert(k, x);
            slrev.insert(slrev.size() - k, x);
        }
        else if (t == 1) {
            int k; scan >> k;
            sl.erase(k);
            slrev.erase(slrev.size() - k - 1);
        }
        else if (t == 2) {
            int l, r; scan >> l >> r;
            auto s11 = split(std::move(sl), l);
            auto s12 = split(std::move(s11.second), r - l);
            int n = slrev.size();
            auto s21 = split(std::move(slrev), n - r);
            auto s22 = split(std::move(s21.second), r - l);
            sl = merge(merge(std::move(s11.first), std::move(s22.first)), std::move(s12.second));
            slrev = merge(merge(std::move(s21.first), std::move(s12.first)), std::move(s22.second));
        }
        else if (t == 3) {
            int l, r; scan >> l >> r;
            mint b, c; scan >> b >> c;
            sl.apply(l, r, {b, c});
            slrev.apply(slrev.size() - r, slrev.size() - l, {b, c});
        }
        else {
            int l, r; scan >> l >> r;
            print << sl.prod(l, r) << endl;
        }
    }
}
