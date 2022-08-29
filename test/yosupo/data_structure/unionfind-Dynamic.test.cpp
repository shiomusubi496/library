#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../../other/template.hpp"
#include "../../../data-struct/unionfind/DynamicUnionFind.hpp"
using namespace std;
int main() {
    int N, Q;
    scan >> N >> Q;
    DynamicUnionFind UF;
    rep (Q) {
        int t, u, v;
        scan >> t >> u >> v;
        if (t == 0) UF.merge(u, v);
        else print << UF.same(u, v) << endl;
    }
}
