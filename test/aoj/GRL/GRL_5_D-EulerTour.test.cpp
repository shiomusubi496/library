#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/BinaryIndexedTree.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/EulerTour.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<int> G(N);
    rep (i, N) {
        int k; scan >> k;
        rep (k) {
            int a; scan >> a;
            G.add_edge(i, a);
        }
    }
    EulerTour<int> ET(G);
    BinaryIndexedTree<int> BIT(2 * N);
    int Q; scan >> Q;
    rep (Q) {
        int q; scan >> q;
        if (q == 0) {
            int a, b; scan >> a >> b;
            auto p = ET.get_idx(a);
            BIT.add(p.first, b);
            BIT.add(p.second, -b);
        }
        else {
            int a; scan >> a;
            int ans = 0;
            ET.each_edge(0, a, [&](int l, int r){ ans += BIT.sum(l, r); });
            print << ans << endl;
        }
    }
}
