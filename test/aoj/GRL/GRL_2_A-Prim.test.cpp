#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/Prim.hpp"
using namespace std;
int main() {
    int V, E; cin >> V >> E;
    Graph<int> G(V);
    rep (E) {
        int a, b, c; cin >> a >> b >> c;
        G.add_edge(a, b, c);
    }
    cout << Prim(G) << endl;
}
