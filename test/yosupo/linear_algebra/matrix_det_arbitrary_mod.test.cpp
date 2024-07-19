#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod"
#include "../../../other/template.hpp"
#include "../../../math/BarrettReduction.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/Determinant.hpp"
using namespace std;
using mint = bmodint;
using matx = Matrix<mint>;
int main() {
    int N, m; scan >> N >> m;
    mint::set_mod(m);
    matx a(N, N); scan >> a;
    prints(determinant_arbitrary_mod(a));
}
