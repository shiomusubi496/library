#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/Prim.hpp"
using namespace std;
int main() {
    int V, E; scan >> V >> E;
    Graph<int> G(V);
    rep (E) {
        int a, b, c; scan >> a >> b >> c;
        G.add_edge(a, b, c);
    }
    print << Prim(G).first << endl;
}
