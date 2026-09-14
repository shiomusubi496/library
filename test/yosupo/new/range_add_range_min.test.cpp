#define PROBLEM "https://judge.yosupo.jp/problem/range_add_range_min"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/LazySegmentTree.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    RangeAddQueryRangeMinimumQuery<ll> seg(A);
    rep (Q) {
        int t, l, r; scan >> t >> l >> r;
        if (t == 0) {
            ll x; scan >> x;
            seg.apply(l, r, x);
        }
        else {
            prints(seg.prod(l, r));
        }
    }
}
