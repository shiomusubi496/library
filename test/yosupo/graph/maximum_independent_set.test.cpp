#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/MaximumIndependentSet.hpp"
using namespace std;
int main() {
    int n, m; scan >> n >> m;
    Graph<int> G(n);
    rep (m) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    MaximumIndependentSet mis(G);
    prints(mis.size());
    prints(mis.get());
}
