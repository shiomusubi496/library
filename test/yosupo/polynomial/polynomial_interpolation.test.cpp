#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/poly/PolynomialInterpolation.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n; scan >> n;
    vector<mint> xs(n), ys(n); scan >> xs >> ys;
    prints(polynomial_interpolation(xs, ys));
}
