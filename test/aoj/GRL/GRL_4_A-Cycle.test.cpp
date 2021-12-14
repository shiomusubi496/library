#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/GraphCycle.hpp"
using namespace std;
int main() {
    int V, E; cin >> V >> E;
    Graph<int> G(V);
    rep (E) {
        int a, b; cin >> a >> b;
        G.add_edge(a, b, true);
    }
    cout << GraphCycle<int>(G).has_cycle() << endl;
}
