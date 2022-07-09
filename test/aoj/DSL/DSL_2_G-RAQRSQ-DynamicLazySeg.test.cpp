#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include "../../../other/template.hpp"
#define protected public
#include "../../../data-struct/segment/DynamicLazySegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    DynamicLazySegmentTree<Monoid::AddSum<ll>> RAQRSQ(n);
    rep (q) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            RAQRSQ.apply(l - 1, r, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << RAQRSQ.prod(l - 1, r) << endl;
        }
    }
}
