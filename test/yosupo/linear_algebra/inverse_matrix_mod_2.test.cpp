#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/Inverse.hpp"
using namespace std;
using mint = static_modint<2>;
using matx = Matrix<mint>;
int main() {
    int N; scan >> N;
    matx A(N, N);
    rep (i, N) rep (j, N) {
        char c; scan >> c;
        A[i][j] = c - '0';
    }
    auto res = inverse(A);
    if (res.empty()) prints(-1);
    else {
        rep (i, N) {
            rep (j, N) print << res[i][j];
            print << '\n';
        }
    }
}
