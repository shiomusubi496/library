#define PROBLEM "https://judge.yosupo.jp/problem/deque_operate_all_composite"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/other/DequeOperateAggregation.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int Q; scan >> Q;
    DequeOperateAggregation<Monoid::Composite<mint>> d;
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            mint a, b; scan >> a >> b;
            d.push_front({a, b});
        }
        else if (t == 1) {
            mint a, b; scan >> a >> b;
            d.push_back({a, b});
        }
        else if (t == 2) d.pop_front();
        else if (t == 3) d.pop_back();
        else {
            mint x; scan >> x;
            auto a = d.all_prod();
            print << a.first * x + a.second << endl;
        }
    }
}
