#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include "../../other/template.hpp"
#include "../../graph/Graph.hpp"
#include "../../graph/tree/CartesianTree.hpp"
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> A(N); cin >> A;
    auto v = CartesianTree<int>(A).get_vec();
    rep (i, N) {
        if (v[i] == -1) v[i] = i;
    }
    cout << v << endl;
}
