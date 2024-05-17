#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/ReRooting.hpp"
using namespace std;
using mint = modint998244353;
struct PairSum {
    using value_type = pair<mint, mint>;
    static value_type op(const value_type& a, const value_type& b) {
        return {a.first + b.first, a.second + b.second};
    }
    static value_type id() { return {0, 0}; }
};
int main() {
    int n; scan >> n;
    vector<mint> a(n); scan >> a;
    Graph<pair<mint, mint>> G(n);
    rep (n - 1) {
        int a, b; scan >> a >> b;
        mint c, d; scan >> c >> d;
        G.add_edge(a, b, {c, d});
    }
    auto f = [&](pair<mint, mint> x, const edge<pair<mint, mint>>& e) -> pair<mint, mint> {
        return {e.cost.first * (x.first + a[e.from]) + e.cost.second * (x.second + 1), x.second + 1};
    };
    auto rr = make_rerooting<PairSum>(G, f);
    rep (i, n) print << rr[i].first + a[i] << " \n"[i == n - 1];
}
