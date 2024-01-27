#define PROBLEM "https://judge.yosupo.jp/problem/gcd_of_gaussian_integers"
#include "../../../other/template.hpp"
#include "../../../math/GaussianInteger.hpp"
using namespace std;
using gint = GaussianInteger<ll>;
int main() {
    int T; scan >> T;
    rep (T) {
        gint a, b; scan >> a >> b;
        prints(gcd(a, b));
    }
}
