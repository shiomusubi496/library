#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../other/template.hpp"
#include "../../data-struct/segment/SegmentTree.hpp"
using namespace std;
constexpr int mod = 998244353;
int main() {
    int N, Q; cin >> N >> Q;
    vector<PLL> A(N); cin >> A;
    SegmentTree<PLL> seg(
        A,
        [](const PLL& a, const PLL& b) -> PLL {
            return {b.first * a.first % mod, (b.first * a.second + b.second) % mod};
        },
        PLL{1, 0}
    );
    rep (Q) {
        int t, a, b, c; cin >> t >> a >> b >> c;
        if (t == 0) seg.set(a, PLL{b, c});
        else {
            PLL p = seg.prod(a, b);
            cout << (p.first * c + p.second) % mod << endl;
        }
    }
}
