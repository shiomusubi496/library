#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/LazySegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    RangeUpdateQueryRangeSumQuery<int, int> seg(n);
    rep (q) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            seg.apply(l, r + 1, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << seg.prod(l, r + 1) << endl;
        }
    }
}
