#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/other/SlidingWindowAggregation.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int Q; scan >> Q;
    SlidingWindowAggregation<Monoid::Composite<mint>> SWAG;
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            mint a, b; scan >> a >> b;
            SWAG.emplace(a, b);
        }
        else if (t == 1) SWAG.pop();
        else {
            mint x; scan >> x;
            auto p = SWAG.all_prod();
            print << p.first * x + p.second << endl;
        }
    }
}
