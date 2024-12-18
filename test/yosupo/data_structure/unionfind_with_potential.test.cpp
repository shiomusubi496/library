#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/unionfind/WeightedUnionFind.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, q; scan >> n >> q;
    WeightedUnionFind<Monoid::Sum<mint>> uf(n);
    rep (q) {
        int t, x, y; scan >> t >> x >> y;
        if (t == 0) {
            mint a; scan >> a;
            auto [p, q] = uf.merge(x, y, a);
            if (q == -2) prints(0);
            else prints(1);
        }
        else {
            if (!uf.same(x, y)) prints(-1);
            else {
                auto a = uf.diff(x, y);
                prints(a);
            }
        }
    }
}
