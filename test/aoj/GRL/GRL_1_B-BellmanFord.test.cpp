#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/BellmanFord.hpp"
using namespace std;
int main() {
    int V, E, r; cin >> V >> E >> r;
    Edges<int> Ed(E);
    each_for (e : Ed) cin >> e.from >> e.to >> e.cost;
    auto dist = BellmanFord(V, Ed, r);
    if (count(all(dist), -infinity<int>::value)) {
        puts("NEGATIVE CYCLE");
        return 0;
    }
    rep (i, V) {
        if (dist[i] == infinity<int>::value) puts("INF");
        else cout << dist[i] << endl;
    }
}