#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_A"
#include "../../../template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/Prim.hpp"
using namespace std;
int main() {
    int n; cin >> n;
    Edges<int> Ed;
    rep (i, n) {
        rep (j, n) {
            int a; cin >> a;
            if (a != -1) {
                Ed.emplace_back(i, j, a);
            }
        }
    }
    cout << Prim(n, Ed) << endl;
}
