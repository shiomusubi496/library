#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/2D/SegmentTree2D.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N), B(N), C(N);
    rep (i, N) scan >> A[i] >> B[i] >> C[i];
    vector<array<ll, 5>> D(Q);
    for (auto&& [a, b, c, d, e] : D) {
        scan >> a;
        if (a == 0) {
            scan >> b >> c >> d;
            A.push_back(b);
            B.push_back(c);
            C.push_back(0);
        }
        else scan >> b >> c >> d >> e;
    }
    SegmentTree2D<Monoid::Sum<ll>> seg(A, B, C);
    for (const auto& [a, b, c, d, e] : D) {
        if (a == 0) seg.apply(b, c, d);
        else prints(seg.prod(b, d, c, e));
    }
}
