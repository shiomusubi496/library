#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#include "../../../other/template.hpp"
#include "../../../math/StirlingNumber.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    prints(stirling_number_2nd<mint>(N));
}
