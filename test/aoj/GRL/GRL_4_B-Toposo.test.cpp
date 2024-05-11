#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_4_B"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/TopologicalSort.hpp"
using namespace std;
int main() {
    int n, m; scan >> n >> m;
    Graph<int> G(n);
    rep (m) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b, true);
    }
    for (const auto& i : TopologicalSort<int>(G).get()) print << i << endl;
}
