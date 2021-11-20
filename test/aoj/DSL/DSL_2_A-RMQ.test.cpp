#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/SegmentTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    SegmentTree<int> seg(n, [](int a, int b) -> int { return min(a, b); }, []() -> int { return (1u << 31) - 1; });
    rep (q) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 0) seg.set(a, b);
        else cout << seg.prod(a, b + 1) << endl;
    }
}
