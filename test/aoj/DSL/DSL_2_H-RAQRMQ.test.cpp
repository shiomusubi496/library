#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/LazySegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    RangeAddQueryRangeMinimumQuery<int, int> seg(vector<int>(n, 0));
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
