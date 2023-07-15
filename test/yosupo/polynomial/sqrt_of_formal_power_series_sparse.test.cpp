#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series_sparse"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/poly/SparseFormalPowerSeries.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, k; scan >> n >> k;
    SparseFPS<mint> a(k); scan >> a;
    auto sq = a.sqrt(n);
    if (sq.empty()) {
        prints(-1);
    } else {
        prints(sq);
    }
}
