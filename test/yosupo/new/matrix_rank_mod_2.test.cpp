#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank_mod_2"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
using namespace std;
using mint = static_modint<2>;
using matx = Matrix<mint>;
int main() {
    int N, M; scan >> N >> M;
    matx A(N, M);
    rep (i, N) rep (j, M) {
        char c; scan >> c;
        A[i][j] = c - '0';
    }
    prints(A.rank());
}
