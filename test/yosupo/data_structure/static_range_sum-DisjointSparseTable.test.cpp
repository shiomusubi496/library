#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DisjointSparseTable.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    DisjointSparseTable<Monoid::Sum<ll>> DST(A);
    rep (Q) {
        int l, r; scan >> l >> r;
        print << DST.prod(l, r) << endl;
    }
}
