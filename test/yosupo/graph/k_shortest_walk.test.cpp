#define PROBLEM "https://judge.yosupo.jp/problem/k_shortest_walk"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/KShortestWalk.hpp"
using namespace std;
int main() {
    int N, M, s, t, K; scan >> N >> M >> s >> t >> K;
    Graph<ll> G(N);
    rep (M) {
        int a, b, c; scan >> a >> b >> c;
        G.add_edge(a, b, c, true);
    }
    KShortestWalk ksw(G, s, t, K);
    for (ll a : ksw.get()) prints(a);
}
