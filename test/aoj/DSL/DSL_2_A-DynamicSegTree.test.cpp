#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DynamicSegmentTree.hpp"
using namespace std;
int main() {
    int n, q; scan >> n >> q;
    DynamicSegmentTree<Monoid::Min<int, -2>> seg(n);
    rep (q) {
        int t, a, b; scan >> t >> a >> b;
        if (t == 0) seg.set(a, b);
        else print << seg.prod(a, b + 1) << endl;
    }
}
