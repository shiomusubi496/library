#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/FrequencyTableofTreeDistance.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<int> G(N);
    rep (N - 1) {
        int a, b; scan >> a >> b;
        G.add_edge(a, b);
    }
    auto ans = FrequencyTableofTreeDistance<int>(G).get();
    ans.erase(ans.begin());
    prints(ans);
}
