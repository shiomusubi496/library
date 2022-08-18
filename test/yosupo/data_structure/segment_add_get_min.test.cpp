#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../../../other/template.hpp"
#include "../../../data-struct/cht/LiChaoTree.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<array<ll, 4>> A(N); cin >> A;
    vector<array<ll, 5>> B(Q);
    each_for ([a, b, c, d, e] : B) {
        cin >> a;
        if (a == 0) cin >> b >> c >> d >> e;
        else cin >> b;
    }
    presser<ll> ps;
    each_const ([a, b, c, d, e] : B) {
        if (a == 1) ps.push_back(b);
    }
    ps.build();
    if (ps.size() == 0) return 0;
    LiChaoTree lct(ps.data());
    each_const ([a, b, c, d] : A) {
        lct.add_segment(ps.lower_bound(a), ps.lower_bound(b), c, d);
    }
    each_const ([a, b, c, d, e] : B) {
        if (a == 0) lct.add_segment(ps.lower_bound(b), ps.lower_bound(c), d, e);
        else {
            ll res = lct.get_min(ps.get(b));
            if (res == infinity<ll>::max) puts("INFINITY");
            else cout << res << endl;
        }
    }
}
