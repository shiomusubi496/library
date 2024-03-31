#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3369"
#include "../../../other/template.hpp"
#include "../../../graph/mst/CountSpanningTree.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, M; scan >> N >> M;
    Graph<int> G(N);
    rep (M) {
        int a, b; scan >> a >> b;
        G.add_edge(--a, --b);
    }
    prints(count_spanning_tree<mint>(G) * (M - N + 1));
}
