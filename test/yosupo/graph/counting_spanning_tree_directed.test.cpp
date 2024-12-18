#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_directed"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/CountSpanningTree.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, M, R; scan >> N >> M >> R;
    Graph<mint> G(N);
    rep (M) {
        int a, b; scan >> a >> b;
        G.add_edge(b, a, 1, true);
    }
    prints(count_spanning_tree<mint>(G, R));
}
