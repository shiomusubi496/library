#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_composite_set_power_series"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/sps/Composite.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int M, N; scan >> M >> N;
    FormalPowerSeries<mint> a(M); scan >> a;
    vector<mint> b(1 << N); scan >> b;
    prints(polynomial_composite_of_sps(a, b));
}
