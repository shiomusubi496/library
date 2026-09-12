#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/StirlingNumber.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n; scan >> n;
    prints(bell_number<mint>(n));
}
