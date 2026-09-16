#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
using namespace std;
using matx = Matrix<bool>;
int main() {
    int N, M, K; scan >> N >> M >> K;
    matx A(N, M), B(M, K);
    rep (i, N) rep (j, M) {
        char c; scan >> c;
        A.get(i, j) = c - '0';
    }
    rep (i, M) rep (j, K) {
        char c; scan >> c;
        B.get(i, j) = c - '0';
    }
    matx C = A * B;
    rep (i, N) rep (j, K) {
        printer << C.get(i, j);
        if (j == K - 1) printer << '\n';
    }
}
