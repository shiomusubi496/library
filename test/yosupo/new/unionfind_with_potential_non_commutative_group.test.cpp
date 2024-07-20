#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/matrix/Matrix.hpp"
#include "../../../data-struct/unionfind/WeightedUnionFind.hpp"
using namespace std;
using mint = modint998244353;
using matx = Matrix<mint>;
struct MatProd {
    using value_type = matx;
    static matx id() { return matx::get_identity(2); }
    static matx op(const matx& a, const matx& b) { return a * b; }
    static matx get_inv(const matx& a) { return matx{{{a[1][1], -a[0][1]}, {-a[1][0], a[0][0]}}}; }
};
int main() {
    int n, q; scan >> n >> q;
    WeightedUnionFind<MatProd> uf(n);
    rep (q) {
        int t, x, y; scan >> t >> x >> y;
        if (t == 0) {
            matx a(2, 2); scan >> a;
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
