#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../math/matrix/LinearEquations.hpp"
using namespace std;
int main() {
    int N, M; scan >> N >> M;
    Matrix<bool> A(N, M);
    rep (i, N) rep (j, M) {
        char c; scan >> c;
        A.get(i, j) = c - '0';
    }
    vector<bool> B(N);
    rep (i, N) {
        char c; scan >> c;
        B[i] = c - '0';
    }
    LinearEquations<bool> le(A, B);
    if (!le.has_solution()) {
        prints(-1);
        return 0;
    }
    prints(le.dimension());
    for (auto b : le.get_solution()) printer << b;
    prints();
    for (const auto& v : le.get_solution_space()) {
        for (auto b : v) printer << b;
        prints();
    }
}
