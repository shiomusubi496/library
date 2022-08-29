#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"
#include "../../../other/template.hpp"
#include "../../../data-struct/unionfind/WeightedUnionFind.hpp"
using namespace std;
int main() {
    int n, q; scan >> n >> q;
    WeightedUnionFind<ll> WUF(n);
    rep (q) {
        int t; scan >> t;
        if (t == 0) {
            int x, y, z; scan >> x >> y >> z;
            WUF.merge(x, y, z);
        }
        else {
            int x, y; scan >> x >> y;
            if (WUF.same(x, y)) print << WUF.diff(x, y) << endl;
            else print << "?" << endl;
        }
    }
}
