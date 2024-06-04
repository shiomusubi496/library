#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/CountSpanningTree.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, M; scan >> N >> M;
    Graph<mint> G(N);
    rep (M) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b, mint{1});
    }
    prints(count_spanning_tree<mint>(G));
}
