#define PROBLEM "https://judge.yosupo.jp/problem/connected_components_of_complement_graph"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/connected/ComplementConnectedComponents.hpp"
using namespace std;
int main() {
    int n, m; scan >> n >> m;
    Graph<int> g(n);
    rep (m) {
        int a, b; scan >> a >> b;
        g.add_edge(a, b);
    }
    ComplementConnectedComponents<int> ccc(g);
    auto v = ccc.groups();
    prints(v.size());
    for (auto t : v) prints(t.size(), t);
}
