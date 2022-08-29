#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/Prim.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    Graph<int> G(n);
    rep (i, n) {
        rep (j, n) {
            int a; scan >> a;
            if (a != -1) {
                G.add_edge(i, j, a, true);
            }
        }
    }
    print << Prim(G) << endl;
}
