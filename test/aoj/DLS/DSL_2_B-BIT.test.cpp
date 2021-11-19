#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../../template.hpp"
#include "../../../data-struct/segment/BinaryIndexedTree.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    BinaryIndexedTree<int> BIT(n);
    rep (q) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 0) BIT.add(a - 1, b);
        else cout << BIT.sum(a - 1, b) << endl;
    }
}
