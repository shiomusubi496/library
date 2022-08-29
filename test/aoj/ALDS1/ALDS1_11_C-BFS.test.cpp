#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_C"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/BreadthFirstSearch.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<int> G(N);
    rep (N) {
        int u; scan >> u;
        int k; scan >> k;
        rep (j, k) {
            int v; scan >> v;
            G.add_edge(u - 1 , v - 1 , true);
        }
    }
    vector<int> dist = BFS(G);
    rep (i, N) {
        print << i + 1 << ' ' << dist[i] << endl;
    }
}
