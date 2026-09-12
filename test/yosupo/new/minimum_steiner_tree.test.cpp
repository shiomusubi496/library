#define PROBLEM "https://judge.yosupo.jp/problem/minimum_steiner_tree"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/MinimumSteinerTree.hpp"
using namespace std;
int main() {
    int N, M; scan >> N >> M;
    Graph<ll> G(N);
    rep (M) {
        int a, b; scan >> a >> b;
        ll c; scan >> c;
        G.add_edge(a, b, c);
    }
    int K; scan >> K;
    vector<int> X(K); scan >> X;
    auto res = minimum_steiner_tree(G, X);
    vector<int> idx;
    rep (i, res.second.size()) idx.push_back(res.second[i].idx);
    prints(res.first, res.second.size());
    prints(idx);
}
