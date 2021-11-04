#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_C"
#include "../../template.hpp"
using namespace std;
int main() {
    int n; cin >> n;
    int l = 1;
    rep (i, n) {
        int a; cin >> a;
        l = lcm(l, a);
    }
    cout << l << endl;
}
