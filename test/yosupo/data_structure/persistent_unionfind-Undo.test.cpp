#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../data-struct/unionfind/UnionFindUndo.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    Graph<PLL> G(Q + 1);
    vector<vector<array<int, 3>>> A(Q + 1);
    rep (i, Q) {
        int t, k, u, v; scan >> t >> k >> u >> v;
        if (t == 0) G.add_edge(k + 1, i + 1, PLL{u, v}, true);
        else A[k + 1].push_back({(int)i, u, v});
    }
    vector<int> ans(Q, -1);
    UnionFindUndo UFU(N);
    struct {
        Graph<PLL>& G;
        vector<vector<array<int, 3>>>& A;
        vector<int>& ans;
        UnionFindUndo& UFU;
        void operator()(int v) {
            for (const auto& a : A[v]) ans[a[0]] = UFU.same(a[1], a[2]);
            for (const auto& e : G[v]) {
                UFU.merge(e.cost.first, e.cost.second);
                this->operator()(e.to);
                UFU.undo();
            }
        }
    } func{G, A, ans, UFU};
    func(0);
    rep (i, Q) {
        if (ans[i] != -1) print << ans[i] << endl;
    }
}
