#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/segment/SegmentTree2D.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<array<ll, 3>> A(N); scan >> A;
    SegmentTree2D<Monoid::Sum<ll>> seg;
    each_const ([a, b, c] : A) seg.add_point(a, b);
    seg.build();
    each_const ([a, b, c] : A) seg.apply(a, b, c);
    rep (Q) {
        ll a, b, c, d; scan >> a >> b >> c >> d;
        print << seg.prod(a, c, b, d) << endl;
    }
}
