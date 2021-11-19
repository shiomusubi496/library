#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../template.hpp"
#include "../../data-struct/segment/DisjointSparseTable.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    cin >> A;
    DisjointSparseTable<int> ST(A, [](int a, int b) -> int { return min(a, b); });
    rep (Q) {
        int l, r; cin >> l >> r;
        cout << ST.query(l, r) << endl;
    }
}
