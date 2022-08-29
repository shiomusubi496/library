#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DynamicLazySegmentTree.hpp"
using namespace std;
int main() {
    int n, q; scan >> n >> q;
    DynamicLazySegmentTree<Monoid::AddSum<ll>> RAQRSQ(n);
    rep (q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r, x; scan >> l >> r >> x;
            RAQRSQ.apply(l - 1, r, x);
        }
        else {
            int l, r; scan >> l >> r;
            print << RAQRSQ.prod(l - 1, r) << endl;
        }
    }
}
