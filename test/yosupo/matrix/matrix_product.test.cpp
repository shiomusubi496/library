#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
using namespace std;
using mint = modint998244353;
using Mat = Matrix<mint>;
int main() {
    int N, M, K; cin >> N >> M >> K;
    Mat A(N, M); cin >> A;
    Mat B(M, K); cin >> B;
    Mat C = A * B;
    each_const (v : C) cout << v << endl;
}
