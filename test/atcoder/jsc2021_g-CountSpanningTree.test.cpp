#define PROBLEM "https://atcoder.jp/contests/jsc2021/tasks/jsc2021_g"
#include "../../other/template.hpp"
#include "../../data-struct/unionfind/UnionFind.hpp"
#include "../../graph/mst/CountSpanningTree.hpp"
#include "../../math/ModInt.hpp"
using namespace std;
using mint = modint1000000007;
int main() {
    int N; scan >> N;
    vector<vector<int>> A(N, vector<int>(N)); scan >> A;
    UnionFind uf(N);
    rep (i, N) rep (j, i) {
        if (A[i][j] == 1) {
            if (uf.merge(i, j).second == -1) {
                prints(0);
                return 0;
            }
        }
    }
    auto v = uf.groups();
    int M = v.size();
    vector<int> B(N);
    rep (i, M) {
        each_const (j : v[i]) B[j] = i;
    }
    Graph<int> G(M);
    rep (i, N) rep (j, i) {
        if (A[i][j] == -1) {
            if (B[i] != B[j]) G.add_edge(B[i], B[j]);
        }
    }
    prints(CountSpanningTree<mint>(G));
}
