#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include "../../../other/template.hpp"
#include "../../../math/SqrtMod.hpp"
using namespace std;
int main() {
    int t; scan >> t;
    rep (t) {
        ll y, p; scan >> y >> p;
        prints(sqrt_mod(y, p));
    }
}
