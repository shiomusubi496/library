#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_mod_2"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/Determinant.hpp"
using namespace std;
using matx = Matrix<bool>;
int main() {
    int N; scan >> N;
    matx A(N, N);
    rep (i, N) rep (j, N) {
        char c; scan >> c;
        A.get(i, j) = c - '0';
    }
    prints(determinant(A));
}
