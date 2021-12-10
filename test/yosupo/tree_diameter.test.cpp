#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../other/template.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/tree/Tree.hpp"
#include "../../graph/tree/TreeDiameter.hpp"
using namespace std;
int main() {
    int N; cin >> N;
    Tree<ll> G(N);
    rep (N - 1) {
        int a, b, c; cin >> a >> b >> c;
        G.add_edge(a, b, c, false);
    }
    TreeDiameter<ll> TD(G);
    auto v = TD.get_path();
    cout << TD.diameter() << ' ' << v.size() + 1 << endl;
    cout << v[0].from;
    for (const edge<ll>& e : v) cout << ' ' << e.to;
    cout << endl;
}
