#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DualSegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    RangeAddQuery<ll> RAQ(std::vector<ll>(n, 0));
    rep (q) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, x; cin >> l >> r >> x;
            RAQ.apply(l, r + 1, x);
        }
        else {
            int k; cin >> k;
            cout << RAQ.get(k) << endl;
        }
    }
}