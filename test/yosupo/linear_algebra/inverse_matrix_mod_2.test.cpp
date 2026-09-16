#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix_mod_2"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/Inverse.hpp"
using namespace std;
using matx = Matrix<bool>;
int main() {
    int N; scan >> N;
    matx A(N, N);
    rep (i, N) rep (j, N) {
        char c; scan >> c;
        A.get(i, j) = c - '0';
    }
    auto res = inverse(A);
    if (res.height() == 0) prints(-1);
    else {
        rep (i, N) {
            rep (j, N) printer << res.get(i, j);
            printer << '\n';
        }
    }
}
