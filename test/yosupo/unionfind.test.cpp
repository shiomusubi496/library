#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../template.cpp"
#include "../../graph/UnionFind.cpp"
using namespace std;
int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind UF(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) UF.merge(u, v);
        else cout << UF.same(u, v) << endl;
    }
}
