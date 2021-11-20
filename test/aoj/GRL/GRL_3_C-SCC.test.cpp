#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_C"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/connected/StronglyConnectedComponents.hpp"
using namespace std;
int main() {
    int v, e; cin >> v >> e;
    Graph<int> G(v);
    rep (e) {
        int u, v; cin >> u >> v;
        G.add_edge(u, v, true);
    }
    StronglyConnectedComponents<int> SCC(G);
    int q; cin >> q;
    rep (q) {
        int a, b; cin >> a >> b;
        cout << (SCC[a] == SCC[b]) << endl;
    }
}
