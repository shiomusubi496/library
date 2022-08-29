#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_A"
#include "../../../other/template.hpp"
#include "../../../data-struct/unionfind/UnionFind.hpp"
using namespace std;
int main() {
    int N, Q;
    scan >> N >> Q;
    UnionFind UF(N);
    rep (Q) {
        int t, u, v;
        scan >> t >> u >> v;
        if (t == 0) UF.merge(u, v);
        else print << UF.same(u, v) << endl;
    }
}
