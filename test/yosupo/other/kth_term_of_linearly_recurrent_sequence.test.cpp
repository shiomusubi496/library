#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"
#include "../../../other/template.hpp"
#include "../../../math/poly/BostanMori.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int d; scan >> d;
    ll k; scan >> k;
    FormalPowerSeries<mint> a(d), c(d); scan >> a >> c;
    c <<= 1;
    c = -c;
    c[0] += 1;
    prints(kth_term(c, a, k));
}
