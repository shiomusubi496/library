#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../../other/template.hpp"
#include "../../other/monoid2.hpp"
#include "../../math/ModInt.hpp"
#include "../../data-struct/structure/SlidingWindowAggregation.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int Q; cin >> Q;
    SlidingWindowAggregation<Monoid::Composite<mint>> SWAG;
    rep (Q) {
        int t; cin >> t;
        if (t == 0) {
            mint a, b; cin >> a >> b;
            SWAG.emplace(a, b);
        }
        else if (t == 1) SWAG.pop();
        else {
            mint x; cin >> x;
            auto p = SWAG.all_prod();
            cout << p.first * x + p.second << endl;
        }
    }
}
