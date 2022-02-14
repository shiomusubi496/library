#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"
#include "../../../other/template.hpp"
#include "../../../data-struct/unionfind/WeightedUnionFind.hpp"
using namespace std;
int main() {
    int n, q; cin >> n >> q;
    WeightedUnionFind<ll> WUF(n);
    rep (q) {
        int t; cin >> t;
        if (t == 0) {
            int x, y, z; cin >> x >> y >> z;
            WUF.merge(x, y, z);
        }
        else {
            int x, y; cin >> x >> y;
            if (WUF.same(x, y)) cout << WUF.diff(x, y) << endl;
            else puts("?");
        }
    }
}
