#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/SparseTable.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    SparseTable<Monoid::Min<int>> ST(A);
    rep (Q) {
        int l, r; scan >> l >> r;
        print << ST.prod(l, r) << endl;
    }
}
