#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include "../../../other/template.hpp"
#include "../../../math/DiscreteLogarithm.hpp"
using namespace std;
int main() {
    int t; scan >> t;
    rep (t) {
        ll x, y, m; scan >> x >> y >> m;
        prints(discrete_logarithm(x, y, m));
    }
}
