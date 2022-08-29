#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DualSegmentTree.hpp"
using namespace std;
int main() {
    int n, q; scan >> n >> q;
    RangeAddQuery<ll> RAQ(n, 0);
    rep (q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r, x; scan >> l >> r >> x;
            RAQ.apply(l - 1, r, x);
        }
        else {
            int k; scan >> k;
            print << RAQ.get(k - 1) << endl;
        }
    }
}
