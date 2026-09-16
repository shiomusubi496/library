#define PROBLEM "https://judge.yosupo.jp/problem/mul_modp_convolution"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/MultiplicationConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int P; scan >> P;
    vector<mint> a(P), b(P); scan >> a >> b;
    prints(multiplication_convolution(a, b));
}
