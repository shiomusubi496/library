#define PROBLEM "https://judge.yosupo.jp/problem/range_parallel_unionfind"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/unionfind/RangeParallelUnionFind.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, Q; scan >> N >> Q;
    vector<mint> X(N); scan >> X;
    RangeParallelUnionFind uf(N);
    mint ans = 0;
    rep (Q) {
        int k, a, b; scan >> k >> a >> b;
        for (auto [x, y] : uf.merge(a, b, k)) {
            ans += X[x] * X[y];
            X[x] += X[y];
            X[y] = 0;
        }
        prints(ans);
    }
}
