#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/ExpPolySum.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    mint r; scan >> r;
    ll d; scan >> d;
    prints(exp_poly_sum(r, d));
}
