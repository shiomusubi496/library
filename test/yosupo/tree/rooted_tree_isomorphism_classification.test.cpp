#define PROBLEM "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/TreeHash.hpp"
using namespace std;
using mint = modint61;
int main() {
    int N; scan >> N;
    Graph<int> G(N);
    rep (i, 1, N) {
        int p; scan >> p;
        G.add_edge(p, i);
    }
    TreeHash th;
    auto h = th.get_hash(G);
    map<ull, vector<int>> mp;
    rep (i, N) mp[h[i].get()].push_back(i);
    vector<int> ans(N);
    int cnt = 0;
    for (const auto& [_, v] : mp) {
        for (int i : v) ans[i] = cnt;
        ++cnt;
    }
    prints(cnt);
    prints(ans);
}
