#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/connected/BiConnectedComponents.hpp"
using namespace std;
int main() {
    int n, m; scan >> n >> m;
    Graph<int> g(n);
    rep (m) {
        int a, b; scan >> a >> b;
        g.add_edge(a, b);
    }
    BiConnectedComponents<int> bcc(g, true);
    auto v = bcc.groups();
    prints(v.size());
    for (auto t : v) prints(t.size(), t);
}
