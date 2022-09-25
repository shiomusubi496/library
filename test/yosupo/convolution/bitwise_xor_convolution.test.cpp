#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/BitwiseXorConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    vector<mint> a(1 << N), b(1 << N);
    scan >> a >> b;
    auto c = bitwise_xor_convolution<mint>(a, b);
    print << c << endl;
}
