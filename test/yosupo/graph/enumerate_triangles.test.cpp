#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/EnumerateTriangles.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, M; scan >> N >> M;
    vector<mint> A(N); scan >> A;
    Graph<int> G(N);
    rep (M) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    mint ans = 0;
    for (auto [a, b, c] : enumerate_triangles(G)) ans += A[a] * A[b] * A[c];
    prints(ans);
}
