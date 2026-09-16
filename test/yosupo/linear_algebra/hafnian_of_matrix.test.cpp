#define PROBLEM "https://judge.yosupo.jp/problem/hafnian_of_matrix"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/Hafnian.hpp"
using namespace std;
using mint = modint998244353;
using matx = Matrix<mint>;
int main() {
    int N; scan >> N;
    matx A(N, N); scan >> A;
    prints(hafnian(A));
}
