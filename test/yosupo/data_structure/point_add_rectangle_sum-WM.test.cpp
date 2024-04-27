#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/wavelet/SegmentTreeWM.hpp"
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
    vector<ll> xs(N), ys(N), zs(N);
    rep (i, N) xs[i] = A[i][0], ys[i] = A[i][1], zs[i] = A[i][2];
    rep (i, Q) {
        if (B[i][0] == 0) {
            xs.push_back(B[i][1]);
            ys.push_back(B[i][2]);
            zs.push_back(0);
        }
    }
    SegmentTreeWM<Monoid::Sum<ll>> wm(xs, ys, zs);
    each_const ([a, b, c, d, e] : B) {
        if (a == 0) wm.apply(b, c, d);
        else print << wm.prod(b, d, c, e) << endl;
    }
}
