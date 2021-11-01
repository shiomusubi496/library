#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"
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
