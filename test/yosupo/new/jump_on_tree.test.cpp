#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/DoublingLowestCommonAncestor.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    Graph<int> G(N);
    rep (N - 1) {
        int a, b; cin >> a >> b;
        G.add_edge(a, b);
    }
    DoublingLCA<int> dlca(G);
    rep (Q) {
        int s, t, k; cin >> s >> t >> k;
        cout << dlca.kth_next_vertext(s, t, k) << endl;
    }
}