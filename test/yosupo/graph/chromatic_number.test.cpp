#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/ChromaticNumber.hpp"
using namespace std;
int main() {
    int n, m; scan >> n >> m;
    Graph<int> G(n);
    rep (m) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    prints(chromatic_number(G));
}
