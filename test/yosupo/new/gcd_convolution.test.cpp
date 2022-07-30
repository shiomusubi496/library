#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/GcdConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; cin >> N;
    vector<mint> A(N + 1), B(N + 1);
    reps (i, N) cin >> A[i];
    reps (i, N) cin >> B[i];
    auto v = gcd_convolution<Monoid::Sum<mint>, Monoid::Product<mint>>(A, B);
    reps (i, N) cout << v[i] << " \n"[i == N];
}
