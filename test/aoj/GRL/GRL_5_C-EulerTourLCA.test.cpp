#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/EulerTour.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<int> G(N);
    rep (i, N) {
        int k; scan >> k;
        rep (k) {
            int t; scan >> t;
            G.add_edge(i, t, true);
        }
    }
    EulerTour<int> T(G);
    int Q; scan >> Q;
    rep (i, Q) {
        int a, b; scan >> a >> b;
        print << T.lca(a, b) << endl;
    }
}
