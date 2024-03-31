#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include "../../../other/template.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
using matx = Matrix<mint>;
int main() {
    int n; ll k; scan >> n >> k;
    matx a(n, n); scan >> a;
    for (auto x : a.pow(k)) prints(x);
}
