#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../template.cpp"
#include "../../graph/UnionFind.cpp"
int main() {
    int N, Q;
    std::cin >> N >> Q;
    UnionFind UF(N);
    while (Q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) UF.merge(u, v);
        else std::cout << UF.same(u, v) << std::endl;
    }
}
