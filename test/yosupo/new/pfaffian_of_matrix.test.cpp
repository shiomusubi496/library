#define PROBLEM "https://judge.yosupo.jp/problem/pfaffian_of_matrix"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/Pfaffian.hpp"
using namespace std;
using mint = modint998244353;
using matx = Matrix<mint>;
int main() {
    int N; scan >> N;
    matx A(2 * N, 2 * N); scan >> A;
    prints(pfaffian(A));
}
