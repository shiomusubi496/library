#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/segment/SegmentTreeBeats.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    SegTreeBeats<ll> seg(A);
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r; scan >> l >> r;
            ll b; scan >> b;
            seg.chmin(l, r, b);
        }
        else if (t == 1) {
            int l, r; scan >> l >> r;
            ll b; scan >> b;
            seg.chmax(l, r, b);
        }
        else if (t == 2) {
            int l, r; scan >> l >> r;
            ll b; scan >> b;
            seg.add(l, r, b);
        }
        else {
            int l, r; scan >> l >> r;
            print << seg.prod_sum(l, r) << endl;
        }
    }
}
