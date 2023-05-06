#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "../../../other/template.hpp"
#include "../../../math/Combinatorics.hpp"
#include "../../../math/BarrettReduction.hpp"
using namespace std;
using mint = bmodint;
using comb = Combinatorics<mint>;
int main() {
    int T, P; scan >> T >> P;
    mint::set_mod(P);
    rep (T) {
        int n, k; scan >> n >> k;
        prints(comb::comb(n, k));
        print << flush;
    }
}
