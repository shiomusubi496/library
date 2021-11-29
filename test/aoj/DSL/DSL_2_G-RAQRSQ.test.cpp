#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/LazySegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    RangeAddQueryRangeSumQuery<ll, ll> seg(n);
    rep (q) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            seg.apply(l - 1, r, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << seg.prod(l - 1, r) << endl;
        }
    }
}
