#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/poly/MultipointEvaluation.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, m; scan >> n >> m;
    FormalPowerSeries<mint> a(n); scan >> a;
    vector<mint> b(m); scan >> b;
    prints(multipoint_evaluation(a, b));
}
