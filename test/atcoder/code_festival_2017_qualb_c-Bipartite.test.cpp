#define PROBLEM "https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c"
#include "../../other/template.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/other/BipartiteGraph.hpp"
using namespace std;
int main() {
    ll N, M; cin >> N >> M;
    UnweightedGraph G(N);
    rep (M) {
        int a, b; cin >> a >> b;
        G.add_edge(a - 1, b - 1);
    }
    BipartiteGraph<unweighted_edge> BG(G);
    if (BG.is_bipartite()) {
        ll a = 0;
        rep (i, N) {
            if (BG.get_label(i)) ++a;
        }
        cout << a * (N - a) - M << endl;
    }
    else {
        cout << N * (N - 1) / 2 - M << endl;
    }
}
