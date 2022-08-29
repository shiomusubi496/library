#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../../other/template.hpp"
#include "../../../data-struct/cht/ConvexHullTrick.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    ConvexHullTrick<ll, false, __int128_t> CHT;
    rep (N) {
        ll a, b; scan >> a >> b;
        CHT.add_line(a, b);
    }
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            ll a, b; scan >> a >> b;
            CHT.add_line(a, b);
        }
        else {
            ll p; scan >> p;
            print << CHT.get_min(p) << endl;
        }
    }
}
