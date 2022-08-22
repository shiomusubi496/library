#define PROBLEM "https://atcoder.jp/contests/agc002/tasks/agc002_d"
#include "../../other/template.hpp"
#include "../../data-struct/unionfind/PartialPersistentUnionFind.hpp"
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    PartialPersistentUnionFind uf(N);
    rep (M) {
        int a, b; cin >> a >> b;
        uf.merge(a - 1, b - 1);
    }
    int Q; cin >> Q;
    rep (Q) {
        int a, b, x; cin >> a >> b >> x;
        --a; --b;
        ll ok = M - 1, ng = -1;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            if ((uf.size(a, mid) + (uf.same(a, b, mid) ? 0 : uf.size(b, mid)) >= x)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << ok + 1 << endl;
    }
}
