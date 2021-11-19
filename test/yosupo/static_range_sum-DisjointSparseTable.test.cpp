#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../template.hpp"
#include "../../data-struct/segment/DisjointSparseTable.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N); cin >> A;
    DisjointSparseTable<ll> DST(A, [](ll a, ll b) { return a + b; });
    rep (Q) {
        int l, r; cin >> l >> r;
        cout << DST.query(l, r) << endl;
    }
}
