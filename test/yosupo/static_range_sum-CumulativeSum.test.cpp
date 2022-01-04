#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../other/template.hpp"
#include "../../data-struct/segment/CumulativeSum.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N); cin >> A;
    CumulativeSum<ll> CS(A);
    rep (Q) {
        int l, r; cin >> l >> r;
        cout << CS.prod(l, r) << endl;
    }
}
