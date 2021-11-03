#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"
#include "../../template.hpp"
#include "../../graph/shortest-path/WarshallFloyd.hpp"
using namespace std;
int main() {
    int V, E; cin >> V >> E;
    auto D = make_vec<ll>(V, V, INF);
    rep (i, E) {
        int s, t, d; cin >> s >> t >> d;
        D[s][t] = d;
    }
    WarshallFloyd(D);
    rep (i, V) {
        if (D[i][i] < 0) {
            puts("NEGATIVE CYCLE");
            return 0;
        }
    }
    rep (i, V) {
        rep (j, V) {
            if (D[i][j] >= INF / 2) cout << "INF";
            else cout << D[i][j];
            cout << " \n"[j == V - 1];
        }
    }
}