#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/LazySegmentTree.hpp"
using namespace std;
int main() {
    int n, q; scan >> n >> q;
    RangeAddQueryRangeMinimumQuery<int> RAQRMQ(n, 0);
    rep (q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r, x; scan >> l >> r >> x;
            RAQRMQ.apply(l, r + 1, x);
        }
        else {
            int l, r; scan >> l >> r;
            print << RAQRMQ.prod(l, r + 1) << endl;
        }
    }
}
