#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"
#include "../../../other/template.hpp"
#include "../../../math/StirlingNumber.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    prints(bernoulli_number<mint>(N));
}
