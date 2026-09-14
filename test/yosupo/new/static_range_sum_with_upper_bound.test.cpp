#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum_with_upper_bound"
#include "../../../other/template.hpp"
#include "../../../data-struct/wavelet/WaveletMatrix.hpp"
#include "../../../data-struct/wavelet/CumulativeSumWM.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    WaveletMatrix<ll> wm(A);
    CumulativeSumWM<Monoid::Sum<ll>> seg([&] {
        vector<ll> A(N); iota(all(A), 0);
        return A;
    }(), A, A);
    rep (Q) {
        int l, r; scan >> l >> r;
        ll x; scan >> x;
        prints(wm.range_freq(l, r, x + 1), seg.prod(l, r, 0, x + 1));
    }
}
