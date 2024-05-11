#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/Kruskal.hpp"
using namespace std;
int main() {
    int V, E; scan >> V >> E;
    Edges<int> Ed(E);
    for (auto&& e : Ed) scan >> e.from >> e.to >> e.cost;
    print << Kruskal(V, Ed).first << endl;
}
