#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/convolution/RelaxedConvolution.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/Combinatorics.hpp"
using namespace std;
using mint = modint998244353;
using comb = Combinatorics<mint>;
int main() {
    int n; scan >> n;
    FormalPowerSeries<mint> a(n); scan >> a;
    RelaxedConvolution<mint> b;
    vector<mint> ans(n);
    comb::init(n);
    ans[0] = 1;
    rep (i, n - 1) {
        ans[i + 1] = b.next(ans[i], a[i + 1] * (i + 1)) * comb::inv(i + 1);
    }
    prints(ans);
}
