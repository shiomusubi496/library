#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/poly/TaylorShift.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n; scan >> n;
    mint c; scan >> c;
    FormalPowerSeries<mint> a(n); scan >> a;
    prints(taylor_shift(a, c));
}
