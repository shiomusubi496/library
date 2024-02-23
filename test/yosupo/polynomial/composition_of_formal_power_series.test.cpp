#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n; scan >> n;
    FormalPowerSeries<mint> f(n), g(n); scan >> f >> g;
    prints(f.compose(g));
}
