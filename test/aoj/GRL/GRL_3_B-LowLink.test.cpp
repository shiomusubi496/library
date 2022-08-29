#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_3_B"
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
    auto v = LL.bridges();
    each_for (e : v) {
        if (e.from > e.to) swap(e.from, e.to);
    }
    sort(v.begin(), v.end(), [](const edge<int>& a, const edge<int>& b) -> bool {
        if (a.from != b.from) return a.from < b.from;
        return a.to < b.to;
    });
    each_const (e : v) print << e.from << ' ' << e.to << endl;
}
