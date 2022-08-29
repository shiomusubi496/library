#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_C"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/Combinatorics.hpp"
using namespace std;
using mint = modint1000000007;
using comb = Combinatorics<mint>;
int main() {
    ll n, k; scan >> n >> k;
    mint ans = 0;
    rep (i, k + 1) {
        ans += mint(-1).pow(k - i) * comb::comb(k, i) * mint(i).pow(n);
    }
    print << ans << endl;
}
