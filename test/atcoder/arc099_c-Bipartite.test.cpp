// #define PROBLEM "https://atcoder.jp/contests/arc099/tasks/arc099_c"
#define PROBLEM "https://atcoder.jp/contests/arc099/tasks/arc099_e"
#include "../../other/template.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/connected/ConnectedComponents.hpp"
#include "../../graph/other/BipartiteGraph.hpp"
using namespace std;
int main() {
    int N, M; scan >> N >> M;
    vector<vector<bool>> A(N, vector<bool>(N, true));
    rep (M) {
        int a, b; scan >> a >> b;
        A[a - 1][b - 1] = A[b - 1][a - 1] = false;
    }
    UnweightedGraph G(N);
    rep (i, N) rep (j, i) {
        if (A[i][j]) G.add_edge(i, j);
    }
    ConnectedComponents<unweighted_edge> CC(G);
    auto g = CC.groups();
    vector<int> B(N);
    each_const (v : g) {
        rep (i, v.size()) B[v[i]] = i;
    }
    vector<UnweightedGraph> C(CC.size());
    rep (i, CC.size()) C[i] = UnweightedGraph(g[i].size());
    each_const (e : UndirectedListToEdges(G)) {
        C[CC[e.from]].add_edge(B[e.from], B[e.to]);
    }
    bitset<701> bs(1);
    each_const (g : C) {
        int n = g.size();
        BipartiteGraph<unweighted_edge> BG(g);
        if (!BG.is_bipartite()) {
            puts("-1");
            return 0;
        }
        int a = 0;
        rep (i, n) if (BG.get_label(i)) ++a;
        bs = (bs << a) | (bs << (n - a));
    }
    int ans = 0;
    rep (i, N + 1) {
        if (bs[i]) chmax(ans, i * (N - i));
    }
    print << N * (N - 1) / 2 - ans << endl;
}
