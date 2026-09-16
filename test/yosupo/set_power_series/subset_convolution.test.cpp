#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/convolution/SubsetConvolution.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    vector<mint> a(1 << N), b(1 << N); scan >> a >> b;
    prints(subset_convolution(a, b));
}
