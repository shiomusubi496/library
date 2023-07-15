#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
#include "../../../other/template.hpp"
#include "../../../math/poly/FormalPowerSeries.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n; scan >> n;
    if (n == 0) {
        prints("1");
        return 0;
    }
    queue<FormalPowerSeries<mint>> que;
    rep (n) {
        int d; scan >> d;
        FormalPowerSeries<mint> f(d + 1); scan >> f;
        que.push(f);
    }
    while (que.size() != 1) {
        FormalPowerSeries<mint> f = que.front(); que.pop();
        FormalPowerSeries<mint> g = que.front(); que.pop();
        que.push(f * g);
    }
    prints(que.front());
}
