#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/Determinant.hpp"
using namespace std;
using mint = modint998244353;
using Mat = Matrix<mint>;
int main() {
    int n; cin >> n;
    Mat a(n, n); cin >> a;
    cout << determinant(a) << endl;
}
