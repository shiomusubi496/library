#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k"
#include "../../../other/template.hpp"
#include "../../../math/StirlingNumber.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, K; scan >> N >> K;
    prints(stirling_number_1st_fixed_k<mint>(K, N));
}
