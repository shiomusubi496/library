#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/BellmanFord.hpp"
using namespace std;
int main() {
    int V, E, r; scan >> V >> E >> r;
    Edges<int> Ed(E);
    for (auto&& e : Ed) scan >> e.from >> e.to >> e.cost;
    auto dist = BellmanFord(V, Ed, r);
    if (count(all(dist), -infinity<int>::value)) {
        print << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep (i, V) {
        if (dist[i] == infinity<int>::value) print << "INF" << endl;
        else print << dist[i] << endl;
    }
}