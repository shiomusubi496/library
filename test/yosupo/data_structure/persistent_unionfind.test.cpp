#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "../../../other/template.hpp"
#include "../../../data-struct/unionfind/PersistentUnionFind.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    PersistentUnionFind uf(n);
    int q; scan >> q;
    vector<int> A(q + 1);
    A[0] = -1;
    rep (i, q) {
        int t, tm, a, b; scan >> t >> tm >> a >> b;
        if (t == 0) {
            A[i + 1] = uf.merge(A[tm + 1], a, b).second;
        }
        else {
            print << uf.same(A[tm + 1], a, b) << endl;
        }
    }
}
