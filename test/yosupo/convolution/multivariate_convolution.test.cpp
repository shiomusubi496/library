#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/MultidimensionalConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int K; scan >> K;
    vector<int> N(K); scan >> N;
    int n = 1;
    rep (i, K) n *= N[i];
    vector<mint> A(n), B(n); scan >> A >> B;
    prints(multidimensional_convolution(A, B, N));
}
