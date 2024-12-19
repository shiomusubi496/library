#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../../other/template.hpp"
#include "../../../math/num/PrimitiveRoot.hpp"
using namespace std;
int main() {
    int q; scan >> q;
    rep (q) {
        ull p; scan >> p;
        prints(primitive_root(p));
    }
}
