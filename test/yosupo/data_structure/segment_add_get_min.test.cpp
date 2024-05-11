#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"
#include "../../../other/template.hpp"
#include "../../../data-struct/cht/LiChaoTree.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<array<ll, 4>> A(N); scan >> A;
    vector<array<ll, 5>> B(Q);
    for (auto&& [a, b, c, d, e] : B) {
        scan >> a;
        if (a == 0) scan >> b >> c >> d >> e;
        else scan >> b;
    }
    compressor<ll> ps;
    for (const auto& [a, b, c, d, e] : B) {
        if (a == 1) ps.push_back(b);
    }
    ps.build();
    if (ps.size() == 0) return 0;
    LiChaoTree lct([&] {
        vector<ll> v;
        rep (i, ps.size()) v.push_back(ps[i]);
        return v;
    }());
    for (const auto& [a, b, c, d] : A) {
        lct.add_segment(ps.lower_bound(a), ps.lower_bound(b), c, d);
    }
    for (const auto& [a, b, c, d, e] : B) {
        if (a == 0) lct.add_segment(ps.lower_bound(b), ps.lower_bound(c), d, e);
        else {
            ll res = lct.get_min(ps.get(b));
            if (res == infinity<ll>::max) print << "INFINITY" << endl;
            else print << res << endl;
        }
    }
}
