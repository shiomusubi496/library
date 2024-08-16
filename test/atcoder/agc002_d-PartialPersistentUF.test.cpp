#define PROBLEM "https://atcoder.jp/contests/agc002/tasks/agc002_d"
#include "../../other/template.hpp"
#include "../../data-struct/unionfind/PartialPersistentUnionFind.hpp"
using namespace std;
int main() {
    int N, M; scan >> N >> M;
    PartialPersistentUnionFind uf(N);
    rep (M) {
        int a, b; scan >> a >> b;
        uf.merge(a - 1, b - 1);
    }
    int Q; scan >> Q;
    rep (Q) {
        int a, b, x; scan >> a >> b >> x;
        --a; --b;
        ll ok = M - 1, ng = -1;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            if ((uf.size(mid, a) + (uf.same(mid, a, b) ? 0 : uf.size(mid, b)) >= x)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        print << ok + 1 << endl;
    }
}
