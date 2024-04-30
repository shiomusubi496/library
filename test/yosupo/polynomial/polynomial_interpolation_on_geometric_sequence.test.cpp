#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/poly/PolynomialInterpolation.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n; scan >> n;
    mint a, r; scan >> a >> r;
    vector<mint> ys(n); scan >> ys;
    prints(polynomial_interpolation_geometric(a, r, ys));
}
