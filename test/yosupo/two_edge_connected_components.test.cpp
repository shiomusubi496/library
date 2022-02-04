#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../../other/template.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/connected/TwoEdgeConnectedComponents.hpp"
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    Graph<int> G(N);
    rep (M) {
        int a, b; cin >> a >> b;
        G.add_edge(a, b);
    }
    auto tecc = TwoEdgeConnectedComponents<int>(G).groups();
    cout << tecc.size() << endl;
    each_const (v : tecc) {
        cout << v.size() << ' ' << v << endl;
    }
}
