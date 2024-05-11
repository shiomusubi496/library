#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/TreeDiameter.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<ll> G(N);
    rep (N - 1) {
        int a, b; ll c; scan >> a >> b >> c;
        G.add_edge(a, b, c);
    }
    TreeDiameter<ll> TD(G);
    auto v = TD.get_path();
    print << TD.diameter() << ' ' << v.size() + 1 << endl;
    print << v[0].from;
    for (const auto& e : v) print << ' ' << e.to;
    print << endl;
}
