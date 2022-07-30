#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/BinaryIndexedTree.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/EulerTour.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<ll> A(N); cin >> A;
    Graph<int> G(N);
    rep (N - 1) {
        int a, b; cin >> a >> b;
        G.add_edge(a, b);
    }
    EulerTour<int> ET(G);
    BinaryIndexedTree<ll> BIT(2 * N);
    rep (i, N) {
        auto p = ET.get_idx(i);
        BIT.add(p.first, A[i]);
        BIT.add(p.second, -A[i]);
    }
    rep (i, Q) {
        int t; cin >> t;
        if (t == 0) {
            int p; ll x; cin >> p >> x;
            auto idx = ET.get_idx(p);
            BIT.add(idx.first, x);
            BIT.add(idx.second, -x);
        }
        else {
            int u, v; cin >> u >> v;
            ll ans = 0;
            ET.each_vertex(u, v, [&](int l, int r) { ans += BIT.sum(l, r); });
            cout << ans << endl;
        }
    }
}
