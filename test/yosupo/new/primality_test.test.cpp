#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "../../../other/template.hpp"
#include "../../../math/MillerRabin.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        ll n; scan >> n;
        prints(is_prime_mr(n) ? "Yes" : "No");
    }
}
