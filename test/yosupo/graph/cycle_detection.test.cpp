#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/GraphCycle.hpp"
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    Graph<int> G(N);
    rep (M) {
        int a, b; cin >> a >> b;
        G.add_edge(a, b, true);
    }
    GraphCycle<int> GC(G);
    if (!GC.has_cycle()) puts("-1");
    else {
        auto v = GC.get_cycle();
        cout << v.size() << endl;
        each_const (e : GC.get_cycle()) cout << e.idx << endl;
    }
}
