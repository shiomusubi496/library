#define PROBLEM "https://atcoder.jp/contests/agc002/tasks/agc002_d"
#include "../../other/template.hpp"
#include "../../data-struct/other/PartialPersistentArray.hpp"
using namespace std;
class PartialPersistentUnionFind {
public:
    int n;
    PartialPersistentArray<int> par;
    std::vector<int> tm;

public:
    PartialPersistentUnionFind(int n) : n(n), par(std::vector<int>(n, -1)), tm{-1} {}
    int find(int t, int x) {
        assert(0 <= x && x < n);
        assert(-1 <= t && t <= par.now());
        return par.get(t, x) < 0 ? x : find(t, par.get(t, x));
    }
    std::pair<int, int> merge(int x, int y) {
        int t = par.now();
        x = find(t, x);
        y = find(t, y);
        if (x == y) {
            tm.push_back((int)tm.back());
            return {x, -1};
        }
        if (par.get(t, x) > par.get(t, y)) std::swap(x, y);
        par.set(x, par.get(t, x) + par.get(t, y));
        par.set(y, x);
        tm.push_back(tm.back() + 2);
        return {x, y};
    }
    bool same(int t, int x, int y) { return find(tm[t + 1], x) == find(tm[t + 1], y); }
    int size(int t, int x) { return -par.get(tm[t + 1], find(tm[t + 1], x)); }
};
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
