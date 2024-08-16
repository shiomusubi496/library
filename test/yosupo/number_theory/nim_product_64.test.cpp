#define PROBLEM "https://judge.yosupo.jp/problem/nim_product_64"
#include "../../../other/template.hpp"
#include "../../../math/NimProduct.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (_, T) {
        ull a, b; scan >> a >> b;
        prints(nim_product(a, b));
    }
}
