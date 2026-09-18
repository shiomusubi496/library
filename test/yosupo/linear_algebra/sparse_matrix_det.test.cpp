#define PROBLEM "https://judge.yosupo.jp/problem/sparse_matrix_det"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/BlackboxLinearAlgebra.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, K; scan >> N >> K;
    std::vector<std::tuple<int, int, mint>> A(K); scan >> A;
    prints(determinant_blackbox<mint>(N, [&](std::vector<mint> b) {
        std::vector<mint> c(N);
        for (const auto& [i, j, x] : A) c[i] += b[j] * x;
        return c;
    }));
}
