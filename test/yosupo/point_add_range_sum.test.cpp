#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../template.hpp"
#include "../../data-struct/segment/BinaryIndexedTree.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    BinaryIndexedTree<ll> BIT(N);
    rep (i, N) {
        int a; cin >> a;
        BIT.add(i, a);
    }
    rep (Q) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 0) BIT.add(a, b);
        else cout << BIT.sum(a, b) << endl;
    }
}
