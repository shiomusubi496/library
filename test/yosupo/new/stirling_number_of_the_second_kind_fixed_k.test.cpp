#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/StirlingNumber.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, k; scan >> n >> k;
    prints(stirling_number_2nd_fixed_k<mint>(k, n));
}
