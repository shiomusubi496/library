#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../other/template.hpp"
#include "../../other/monoid2.hpp"
#include "../../math/ModInt.hpp"
#include "../../data-struct/segment/SegmentTree.hpp"
using namespace std;
using mint = modint998244353;
using PMM = pair<mint, mint>;
int main() {
    int N, Q; cin >> N >> Q;
    vector<PMM> A(N); cin >> A;
    SegmentTree<Monoid::Composite<mint>> seg(A);
    rep (Q) {
        int t, a, b, c; cin >> t >> a >> b >> c;
        if (t == 0) seg.set(a, PMM{b, c});
        else {
            PMM p = seg.prod(a, b);
            cout << p.first * c + p.second << endl;
        }
    }
}
