#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_add_point_get"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/2D/DualSegmentTree2D.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<array<ll, 5>> A(N); scan >> A;
    vector<array<ll, 6>> D(Q);
    vector<ll> B, C;
    for (auto&& [a, b, c, d, e, f] : D) {
        scan >> a;
        if (a == 0) scan >> b >> c >> d >> e >> f;
        else {
            scan >> b >> c;
            B.push_back(b);
            C.push_back(c);
        }
    }
    DualSegmentTree2D<Monoid::Sum<ll>> seg(B, C);
    for (const auto& [a, b, c, d, e] : A) seg.apply(a, c, b, d, e);
    for (const auto& [a, b, c, d, e, f] : D) {
        if (a == 0) seg.apply(b, d, c, e, f);
        else prints(seg.get(b, c));
    }
}
