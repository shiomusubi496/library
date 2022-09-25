#define PROBLEM "https://judge.yosupo.jp/problem/montmort_number_mod"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/MontmortNumber.hpp"
using mint = modint;
int main() {
    int N, M; scan >> N >> M;
    mint::set_mod(M);
    auto v = monmort_number<mint>(N);
    rep (i, 1, v.size()) print << ' ' << v[i];
    print << endl;
}
