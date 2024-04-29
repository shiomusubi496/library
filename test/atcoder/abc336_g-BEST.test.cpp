#define PROBLEM "https://atcoder.jp/contests/abc336/tasks/abc336_g"
#include "../../other/template.hpp"
#include "../../math/Combinatorics.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/other/CountEulerianTrail.hpp"
using namespace std;
using mint = modint998244353;
using comb = Combinatorics<mint>;
int main() {
    vector<int> A(16); scan >> A;
    Graph<int> G(8);
    rep (i, 16) {
        G.add_edge(i / 2, i % 8, A[i], true);
    }
    mint ans = 0;
    rep (i, 8) rep (j, 8) {
        Graph<int> H = G;
        H.add_edge(i, j, true);
        ans += count_eulerian_trail<mint>(H);
    }
    rep (i, 16) ans *= comb::finv(A[i]);
    prints(ans);
}
