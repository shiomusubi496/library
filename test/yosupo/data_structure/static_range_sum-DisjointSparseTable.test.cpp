#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DisjointSparseTable.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N); cin >> A;
    DisjointSparseTable<Monoid::Sum<ll>> DST(A);
    rep (Q) {
        int l, r; cin >> l >> r;
        cout << DST.prod(l, r) << endl;
    }
}
