#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DynamicSegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    DynamicSegmentTree<Monoid::Min<int, (1ull << 31) - 1>> seg(n);
    rep (q) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 0) seg.set(a, b);
        else cout << seg.prod(a, b + 1) << endl;
    }
}
