#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/CartesianTree.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    vector<int> A(N); scan >> A;
    auto v = CartesianTree<int>(A).get_vec();
    rep (i, N) {
        if (v[i] == -1) v[i] = i;
    }
    print << v << endl;
}
