#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"
#include "../../../other/template.hpp"
#include "../../../math/ArbitraryModCombinatorics.hpp"
using namespace std;
using comb = ArbitraryModCombinatorics<>;
int main() {
    int q, m; scan >> q >> m;
    comb::set_mod(m);
    rep (q) {
        ll n, k; scan >> n >> k;
        prints(comb::comb(n, k));
    }
}

