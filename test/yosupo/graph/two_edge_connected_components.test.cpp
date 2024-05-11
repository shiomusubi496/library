#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/connected/TwoEdgeConnectedComponents.hpp"
using namespace std;
int main() {
    int N, M; scan >> N >> M;
    Graph<int> G(N);
    rep (M) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    auto tecc = TwoEdgeConnectedComponents<int>(G).groups();
    print << tecc.size() << endl;
    for (const auto& v : tecc) {
        print << v.size() << ' ' << v << endl;
    }
}
