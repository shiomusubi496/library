#define PROBLEM "https://judge.yosupo.jp/problem/lcm_convolution"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/LcmConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    vector<mint> A(N + 1), B(N + 1);
    reps (i, N) scan >> A[i];
    reps (i, N) scan >> B[i];
    auto v = lcm_convolution<Monoid::Sum<mint>, Monoid::Product<mint>>(A, B);
    reps (i, N) print << v[i] << " \n"[i == N];
}
