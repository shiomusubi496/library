#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/LinearEquations.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, M; scan >> N >> M;
    Matrix<mint> A(N, M); scan >> A;
    vector<mint> B(N); scan >> B;
    LinearEquations<mint> le(A, B);
    if (!le.has_solution()) {
        prints(-1);
        return 0;
    }
    prints(le.dimension());
    prints(le.get_solution());
    for (const auto& v : le.get_solution_space()) prints(v);
}
