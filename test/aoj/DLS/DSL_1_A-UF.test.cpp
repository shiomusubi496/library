#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A"
#include "../../../template.hpp"
#include "../../../graph/UnionFind.hpp"
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind UF(N);
    rep (Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) UF.merge(u, v);
        else cout << UF.same(u, v) << endl;
    }
}
