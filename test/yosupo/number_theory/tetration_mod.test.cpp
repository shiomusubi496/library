#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"
#include "../../../other/template.hpp"
#include "../../../math/TetrationMod.hpp"
using namespace std;
int main() {
    int t; scan >> t;
    rep (t) {
        ll a, b, m; scan >> a >> b >> m;
        prints(tetration(a, b, m));
    }
}
