#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/BinaryIndexedTree.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    BinaryIndexedTree<ll> BIT(N);
    rep (i, N) {
        int a; scan >> a;
        BIT.add(i, a);
    }
    rep (Q) {
        int t, a, b; scan >> t >> a >> b;
        if (t == 0) BIT.add(a, b);
        else print << BIT.sum(a, b) << endl;
    }
}
