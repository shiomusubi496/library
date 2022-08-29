#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DualSegmentTree.hpp"
using namespace std;
int main() {
    int n, q; scan >> n >> q;
    RangeUpdateQuery<int> RUQ(n, (1ull << 31) - 1);
    rep (q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r, x; scan >> l >> r >> x;
            RUQ.apply(l, r + 1, x);
        }
        else {
            int k; scan >> k;
            print << RUQ.get(k) << endl;
        }
    }
}
