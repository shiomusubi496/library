#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n; scan >> n;
    FormalPowerSeries<mint> a(n); scan >> a;
    auto sq = a.sqrt();
    if (sq.empty()) {
        prints(-1);
    } else {
        prints(sq);
    }
}
