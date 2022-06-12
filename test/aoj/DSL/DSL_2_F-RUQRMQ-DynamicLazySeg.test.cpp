#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DynamicLazySegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    DynamicLazySegmentTree<Monoid::AssignMin<int, (1ull << 31) - 1>> RUQRMQ(n);
    rep (q) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            RUQRMQ.apply(l, r + 1, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << RUQRMQ.prod(l, r + 1) << endl;
        }
    }
}
