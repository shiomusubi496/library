#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, m; scan >> n >> m;
    FormalPowerSeries<mint> a(n), b(m); scan >> a >> b;
    auto [q, r] = divmod(a, b);
    prints(q.size(), r.size());
    prints(q);
    prints(r);
}
