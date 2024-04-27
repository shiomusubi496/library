#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/wavelet/CumulativeSumWM.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N), B(N), C(N);
    rep (i, N) scan >> A[i] >> B[i] >> C[i];
    CumulativeSumWM<Monoid::Sum<ll>> seg(A, B, C);
    rep (Q) {
        ll a, b, c, d; scan >> a >> b >> c >> d;
        print << seg.prod(a, c, b, d) << endl;
    }
}
