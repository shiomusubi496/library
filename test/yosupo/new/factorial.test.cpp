#define PROBLEM "https://judge.yosupo.jp/problem/factorial"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/Factorial.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int T; scan >> T;
    rep (T) {
        ll n; scan >> n;
        prints(factorial<mint>(n));
    }
}
