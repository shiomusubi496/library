#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/DisjointSparseTable.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); cin >> A;
    DisjointSparseTable<Monoid::Min<int>> ST(A);
    rep (Q) {
        int l, r; cin >> l >> r;
        cout << ST.prod(l, r) << endl;
    }
}
