#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/Inverse.hpp"
using mint = modint998244353;
int main() {
    int n; scan >> n;
    Matrix<mint> mat(n, n); scan >> mat;
    Matrix<mint> res = inverse(mat);
    if (res.empty()) prints(-1);
    else {
        rep (i, n) prints(res[i]);
    }
}
