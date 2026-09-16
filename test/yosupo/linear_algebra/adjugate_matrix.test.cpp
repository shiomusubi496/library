#define PROBLEM "https://judge.yosupo.jp/problem/adjugate_matrix"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/AdjugateMatrix.hpp"
using namespace std;
using mint = modint998244353;
using matx = Matrix<mint>;
int main() {
    int N; scan >> N;
    matx A(N, N); scan >> A;
    auto B = adjugate_matrix(A);
    rep (i, N) prints(B[i]);
}
