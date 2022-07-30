#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../../../other/template.hpp"
#include "../../../data-struct/cht/ConvexHullTrick.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    ConvexHullTrick<ll, false, __int128_t> CHT;
    rep (N) {
        ll a, b; cin >> a >> b;
        CHT.add_line(a, b);
    }
    rep (Q) {
        int t; cin >> t;
        if (t == 0) {
            ll a, b; cin >> a >> b;
            CHT.add_line(a, b);
        }
        else {
            ll p; cin >> p;
            cout << CHT.get_min(p) << endl;
        }
    }
}
