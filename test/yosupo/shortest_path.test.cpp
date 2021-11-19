#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../template.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/shortest-path/Dijkstra.hpp"
#include "../../graph/shortest-path/Restore.hpp"
using namespace std;
int main() {
    int N, M, s, t; cin >> N >> M >> s >> t;
    Graph<ll> G(N);
    rep (M) {
        int a, b, c; cin >> a >> b >> c;
        G.add_edge(a, b, c, true);
    }
    vector<ll> D = Dijkstra(G, s);
    vector<int> R = Restore(G, D, s);
    if (R[t] == -2) {
        puts("-1");
        return 0;
    }
    vector<int> ans{t};
    while (ans.back() != s) ans.push_back(R[ans.back()]);
    reverse(all(ans));
    cout << D[t] << ' ' << ans.size() - 1 << endl;
    rep (i, ans.size() - 1) cout << ans[i] << ' ' << ans[i + 1] << endl;
}
