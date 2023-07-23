#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/bst/SplayTree.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, Q; scan >> N >> Q;
    vector<mint> A(N); scan >> A;
    SplayTree<Monoid::AffineSum<mint>> st(A);
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int k; scan >> k;
            mint x; scan >> x;
            st.insert(k, x);
        }
        else if (t == 1) {
            int k; scan >> k;
            st.erase(k);
        }
        else if (t == 2) {
            int l, r; scan >> l >> r;
            st.reverse(l, r);
        }
        else if (t == 3) {
            int l, r; scan >> l >> r;
            mint b, c; scan >> b >> c;
            st.apply(l, r, {b, c});
        }
        else {
            int l, r; scan >> l >> r;
            prints(st.prod(l, r));
        }
    }
}
