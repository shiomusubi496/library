#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/Dijkstra.hpp"
#include "../../../graph/shortest-path/Restore.hpp"
using namespace std;
int main() {
    int N, M, s, t; cin >> N >> M >> s >> t;
    Graph<ll> G(N);
    rep (M) {
        int a, b, c; cin >> a >> b >> c;
        G.add_edge(a, b, c, true);
    }
    vector<ll> D = Dijkstra(G, s);
    if (D[t] == infinity<ll>::value) {
        puts("-1");
        return 0;
    }
    Edges<ll> R = RestorePath(G, D, s, t);
    cout << D[t] << ' ' << R.size() << endl;
    each_const (e : R) cout << e.from << ' ' << e.to << endl;
}
