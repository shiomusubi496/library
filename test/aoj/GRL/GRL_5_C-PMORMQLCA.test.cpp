#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/PMORMQLCA.hpp"
using namespace std;
int main() {
    int N; cin >> N;
    Graph<int> G(N);
    rep (i, N) {
        int k; cin >> k;
        rep (k) {
            int t; cin >> t;
            G.add_edge(i, t, true);
        }
    }
    PMORMQLCA<int> T(G);
    int Q; cin >> Q;
    rep (i, Q) {
        int a, b; cin >> a >> b;
        cout << T.lca(a, b) << endl;
    }
}
