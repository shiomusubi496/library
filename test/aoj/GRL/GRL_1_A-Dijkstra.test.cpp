#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/Dijkstra.hpp"
using namespace std;
int main() {
    int V, E, r; cin >> V >> E >> r;
    Graph<int> G(V);
    rep (E) {
        int s, t, d; cin >> s >> t >> d;
        G.add_edge(s, t, d, true);
    }
    vector<int> dist = Dijkstra(G, r);
    rep (i, V) {
        if (dist[i] == infinity<int>::value) puts("INF");
        else cout << dist[i] << endl;
    }
}
