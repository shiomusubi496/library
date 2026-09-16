#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/poly/BerlekampMassey.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    vector<mint> a(N); scan >> a;
    auto f = berlekamp_massey(a);
    f = -(f >> 1);
    prints(f.size());
    prints(f);
}
