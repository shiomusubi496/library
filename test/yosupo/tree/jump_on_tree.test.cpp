#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/DoublingLowestCommonAncestor.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    Graph<int> G(N);
    rep (N - 1) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    DoublingLCA<int> dlca(G);
    rep (Q) {
        int s, t, k; scan >> s >> t >> k;
        print << dlca.kth_next_vertex(s, t, k) << endl;
    }
}
