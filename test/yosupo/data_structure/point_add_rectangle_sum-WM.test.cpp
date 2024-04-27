#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/wavelet/WaveletMatrixPointAddRectangleSum.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<array<ll, 3>> A(N); scan >> A;
    vector<array<ll, 5>> B(Q);
    each_for ([a, b, c, d, e] : B) {
        scan >> a;
        if (a == 0) scan >> b >> c >> d;
        else scan >> b >> c >> d >> e;
    }
    WaveletMatrixPointAddRectangleSum<ll, Monoid::Sum<ll>> wm;
    rep (i, N) wm.add_point(A[i][0], A[i][1]);
    rep (i, Q) {
        if (B[i][0] == 0) wm.add_point(B[i][1], B[i][2]);
    }
    wm.build();
    rep (i, N) wm.apply(A[i][0], A[i][1], A[i][2]);
    each_const ([a, b, c, d, e] : B) {
        if (a == 0) wm.apply(b, c, d);
        else print << wm.prod(b, d, c, e) << endl;
    }
}
