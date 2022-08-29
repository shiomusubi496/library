#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_C"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/WarshallFloyd.hpp"
using namespace std;
int main() {
    int V, E; scan >> V >> E;
    auto D = make_vec<ll>(V, V, infinity<ll>::value);
    rep (E) {
        int s, t, d; scan >> s >> t >> d;
        D[s][t] = d;
    }
    WarshallFloyd(D);
    rep (i, V) {
        if (D[i][i] < 0) {
            print << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    rep (i, V) {
        rep (j, V) {
            if (D[i][j] == infinity<ll>::value) print << "INF";
            else print << D[i][j];
            print << " \n"[j == V - 1];
        }
    }
}
