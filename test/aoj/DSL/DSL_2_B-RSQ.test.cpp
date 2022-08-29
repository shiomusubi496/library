#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/SegmentTree.hpp"
using namespace std;
int main() {
    int n, q; scan >> n >> q;
    RangeSumQuery<int> RSQ(n);
    rep (q) {
        int t, a, b; scan >> t >> a >> b;
        if (t == 0) RSQ.apply(a - 1, b);
        else print << RSQ.prod(a - 1, b) << endl;
    }
}
