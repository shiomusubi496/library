#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/BitwiseOrConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    vector<mint> a(1 << N), b(1 << N);
    scan >> a >> b;
    reverse(all(a)); reverse(all(b));
    auto c = bitwise_or_convolution<mint>(a, b);
    reverse(all(c));
    print << c << endl;
}
