#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/EnumerateCliques.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, m; scan >> n >> m;
    vector<mint> a(n); scan >> a;
    Graph<int> G(n);
    rep (m) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    mint ans = 0;
    for (auto v : enumerate_cliques(G)) {
        mint p = 1;
        each_const (i : v) p *= a[i];
        ans += p;
    }
    prints(ans);
}
