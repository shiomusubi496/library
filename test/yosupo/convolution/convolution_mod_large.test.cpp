#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_large"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/LargeConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, m; scan >> n >> m;
    vector<mint> a(n), b(m); scan >> a >> b;
    prints(convolution_large(a, b));
}
