#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../other/template.hpp"
#include "../../data-struct/segment/LCARMQ.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); cin >> A;
    LCARMQ<int> ST(A);
    rep (Q) {
        int l, r; cin >> l >> r;
        cout << ST.prod(l, r) << endl;
    }
}
