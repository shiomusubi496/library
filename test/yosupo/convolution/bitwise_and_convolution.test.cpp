#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/BitwiseAndConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    vector<mint> a(1 << N), b(1 << N);
    scan >> a >> b;
    auto c = bitwise_and_convolution<Monoid::Sum<mint>, Monoid::Product<mint>>(a, b);
    print << c << endl;
}
