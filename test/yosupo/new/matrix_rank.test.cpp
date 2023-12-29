#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include "../../../other/template.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
using matx = Matrix<mint>;
int main() {
    int n, m; scan >> n >> m;
    matx a(n, m); scan >> a;
    prints(a.rank());
}
