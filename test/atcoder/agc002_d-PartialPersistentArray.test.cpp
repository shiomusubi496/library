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
    int find(int x, int t) {
        assert(0 <= x && x < n);
        assert(-1 <= t && t <= par.now());
        return par.get(x, t) < 0 ? x : find(par.get(x, t), t);
    }
    std::pair<int, int> merge(int x, int y) {
        int t = par.now();
        x = find(x, t);
        y = find(y, t);
        if (x == y) {
            tm.push_back((int)tm.back());
            return {x, -1};
        }
        if (par.get(x, t) > par.get(y, t)) std::swap(x, y);
        par.set(x, par.get(x, t) + par.get(y, t));
        par.set(y, x);
        tm.push_back(tm.back() + 2);
        return {x, y};
    }
    bool same(int x, int y, int t) { return find(x, tm[t + 1]) == find(y, tm[t + 1]); }
    int size(int x, int t) { return -par.get(find(x, tm[t + 1]), tm[t + 1]); }
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
            if ((uf.size(a, mid) + (uf.same(a, b, mid) ? 0 : uf.size(b, mid)) >= x)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        print << ok + 1 << endl;
    }
}
