#define PROBLEM "https://judge.yosupo.jp/problem/counting_eulerian_circuits"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/CountEulerianCircuit.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, M; scan >> N >> M;
    Graph<int> G(N);
    rep (M) {
        int a, b; scan >> a >> b;
        G.add_edge(b, a, 1, true);
    }
    prints(count_eulerian_circuit<mint>(G));
}
