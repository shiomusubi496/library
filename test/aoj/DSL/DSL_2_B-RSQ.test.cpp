#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/SegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    RangeSumQuery<int> seg(n);
    rep (q) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 0) seg.apply(a - 1, b);
        else cout << seg.prod(a - 1, b) << endl;
    }
}
