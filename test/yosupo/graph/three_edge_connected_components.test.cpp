#define PROBLEM "https://judge.yosupo.jp/problem/three_edge_connected_components"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/connected/ThreeEdgeConnectedComponents.hpp"
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    Graph<int> g(n);
    rep (m) {
        int a, b; cin >> a >> b;
        g.add_edge(a, b);
    }
    ThreeEdgeConnectedComponents<int> tecc(g);
    printer << tecc.size() << endl;
    for (auto g : tecc.groups()) {
        printer << g.size();
        for (auto v : g) printer << " " << v;
        printer << endl;
    }
}
