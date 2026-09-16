#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/sps/Composite.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    vector<mint> a(1 << N); scan >> a;
    prints(exp_of_sps(a));
}
