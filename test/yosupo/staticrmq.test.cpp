#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../segment/SparseTable.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for (auto&& i : A) cin >> i;
    SparseTable<int> ST(A, [](int a, int b) -> int { return min(a, b); });
    vector<int> res;
    rep (i, Q) {
        int l, r; cin >> l >> r;
        cout << ST.query(l, r) << endl;
    }
}