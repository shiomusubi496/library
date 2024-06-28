#define PROBLEM "https://judge.yosupo.jp/problem/common_interval_decomposition_tree"
#include "../../../other/template.hpp"
#include "../../../graph/tree/PermutationTree.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    vector<int> P(N); scan >> P;
    PermutationTree pt(P);
    prints(pt.size());
    rep (i, pt.size()) {
        prints(pt.par(i), pt.l(i), pt.r(i) - 1, pt.is_linear(i) ? "linear" : "prime");
    }
}
