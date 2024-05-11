#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/LowLink.hpp"
using namespace std;
int main() {
    int V, E; scan >> V >> E;
    Graph<int> G(V);
    rep (E) {
        int s, t; scan >> s >> t;
        G.add_edge(s, t);
    }
    LowLink<int> LL(G);
    auto v = LL.articulation_points();
    sort(v.begin(), v.end());
    for (const auto& i : v) { print << i << endl; }
}
