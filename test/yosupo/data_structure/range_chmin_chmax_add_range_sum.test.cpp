#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/segment/SegmentTreeBeats.hpp"
using namespace std;
int main() {
    using Action = Monoid::ChmaxChminAddAssignMaxMinSum<ll>;
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    SegmentTreeBeats<Action> seg([&] {
        vector<typename Action::M::value_type> B(N);
        rep (i, N) B[i] = Action::M::get(A[i]);
        return B;
    }());
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int l, r; scan >> l >> r;
            ll b; scan >> b;
            auto x = Action::E::id();
            x.mn = b;
            seg.apply(l, r, x);
        }
        else if (t == 1) {
            int l, r; scan >> l >> r;
            ll b; scan >> b;
            auto x = Action::E::id();
            x.mx = b;
            seg.apply(l, r, x);
        }
        else if (t == 2) {
            int l, r; scan >> l >> r;
            ll b; scan >> b;
            auto x = Action::E::id();
            x.ad = b;
            seg.apply(l, r, x);
        }
        else {
            int l, r; scan >> l >> r;
            print << seg.prod(l, r).sm << endl;
        }
    }
}
