#define PROBLEM "https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/poly/SamplingPointsShift.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, m; scan >> n >> m;
    mint c; scan >> c;
    vector<mint> a(n); scan >> a;
    prints(sampling_points_shift(a, m, c));
}
