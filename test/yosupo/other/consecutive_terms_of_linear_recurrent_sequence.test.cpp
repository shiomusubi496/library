#define PROBLEM "https://judge.yosupo.jp/problem/consecutive_terms_of_linear_recurrent_sequence"
#include "../../../other/template.hpp"
#include "../../../math/poly/ConsecutiveTermsOfLinearRecurrence.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int d; scan >> d;
    ll k; scan >> k;
    int m; scan >> m;
    FormalPowerSeries<mint> a(d), c(d); scan >> a >> c;
    c <<= 1;
    c = -c;
    c[0] += 1;
    prints(range_terms(c, a, k, m));
}
