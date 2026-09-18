#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_polynomial"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/ChromaticPolynomial.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, m; scan >> n >> m;
    Graph<int> G(n);
    rep (m) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    prints(chromatic_polynomial<mint>(G));
}
