#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/flow/MaxFlow.hpp"
int main() {
    int L, R, M; scan >> L >> R >> M;
    MaxFlow<int> mf(L + R + 2);
    int s = L + R, t = L + R + 1;
    rep (i, L) mf.add_edge(s, i, 1);
    rep (i, R) mf.add_edge(L + i, t, 1);
    rep (M) {
        int a, b; scan >> a >> b;
        mf.add_edge(a, L + b, 1);
    }
    prints(mf.flow(s, t));
    for (auto e : mf.edges()) {
        if (e.from == s || e.to == t || e.flow == 0) continue;
        prints(e.from, e.to - L);
    }
}
