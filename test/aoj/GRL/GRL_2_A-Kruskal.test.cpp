#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/Kruskal.hpp"
using namespace std;
int main() {
    int V, E; cin >> V >> E;
    Edges<int> Ed(E);
    each_for (e : Ed) cin >> e.from >> e.to >> e.cost;
    cout << Kruskal(V, Ed) << endl;
}
