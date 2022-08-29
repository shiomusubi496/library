#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_D"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/connected/ConnectedComponents.hpp"
using namespace std;
int main() {
    int n, m; scan >> n >> m;
    Graph<int> G(n);
    rep (m) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    ConnectedComponents<int> CC(G);
    int q; scan >> q;
    rep (q) {
        int a, b; scan >> a >> b;
        if (CC[a] == CC[b]) puts("yes");
        else puts("no");
    }
}
