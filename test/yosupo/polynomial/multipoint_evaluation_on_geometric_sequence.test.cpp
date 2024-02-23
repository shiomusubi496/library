#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/poly/MultipointEvaluation.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, m; scan >> n >> m;
    mint a, r; scan >> a >> r;
    FormalPowerSeries<mint> f(n); scan >> f;
    prints(multipoint_evaluation_geometric(f, a, r, m));
}
