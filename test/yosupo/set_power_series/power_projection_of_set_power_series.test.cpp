#define PROBLEM "https://judge.yosupo.jp/problem/power_projection_of_set_power_series"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/poly/SetPowerSeries.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, M; scan >> N >> M;
    std::vector<mint> a(1 << N), w(1 << N); scan >> a >> w;
    prints(power_projection_of_sps(a, w, M));
}
