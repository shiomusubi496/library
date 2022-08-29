#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/GraphCycle.hpp"
using namespace std;
int main() {
    int V, E; scan >> V >> E;
    Graph<int> G(V);
    rep (E) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b, true);
    }
    print << GraphCycle<int>(G).has_cycle() << endl;
}
