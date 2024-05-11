#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/GraphCycle.hpp"
using namespace std;
int main() {
    int N, M; scan >> N >> M;
    Graph<int> G(N);
    rep (M) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b, true);
    }
    GraphCycle<int> GC(G);
    if (!GC.has_cycle()) print << "-1" << endl;
    else {
        auto v = GC.get_cycle();
        print << v.size() << endl;
        for (const auto& e : GC.get_cycle()) print << e.idx << endl;
    }
}
