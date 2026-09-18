#define PROBLEM "https://judge.yosupo.jp/problem/prefix_sum_of_polynomial"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/poly/PolynomialPrefixSum.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    FormalPowerSeries<mint> f(N); scan >> f;
    prints(polynomial_prefix_sum(f));
}
