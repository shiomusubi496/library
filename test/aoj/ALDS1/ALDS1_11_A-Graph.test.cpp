#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_11_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<int> G(N);
    rep (i, N) {
        int v, k; scan >> v >> k;
        --v;
        rep (k) {
            int u; scan >> u;
            G.add_edge(v, u - 1, true);
        }
    }
    GMatrix<int> GM = ListToMatrix(G);
    for (const auto& v : GM) {
        rep (i, N) {
            if (v[i] == 1) print << 1;
            else print << 0;
            print << " \n"[i == N - 1];
        }
    }
}
