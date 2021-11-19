#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"
#include "../../../template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/Prim.hpp"
using namespace std;
int main() {
    int V, E; cin >> V >> E;
    Edges<int> Ed(E);
    for (auto&& e : Ed) cin >> e.from >> e.to >> e.cost;
    cout << Prim(V, Ed) << endl;
}
