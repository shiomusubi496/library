#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"
#include "../../../other/template.hpp"
#include "../../../data-struct/bst/SplayTree.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    SplayTree<Monoid::AddSum<ll>> st(A);
    rep (Q) {
        int t, l, r; scan >> t >> l >> r;
        if (t == 0) st.reverse(l, r);
        else prints(st.prod(l, r));
    }
}
