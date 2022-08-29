#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/TreeDiameter.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<int> G(N);
    rep (N - 1) {
        int a, b, c;
        scan >> a >> b >> c;
        G.add_edge(a, b, c);
    }
    TreeDiameter<int> TD(G);
    print << TD.diameter() << endl;
}
