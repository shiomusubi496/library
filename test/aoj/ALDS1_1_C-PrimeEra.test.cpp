#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C"
#include "../../template.hpp"
#include "../../math/PrimeFactor.hpp"
using namespace std;
int main() {
    int n; cin >> n;
    PrimeFactor PF(100000000);
    int ans = 0;
    rep (i, n) {
        int a; cin >> a;
        if (PF.is_prime(a)) ans++;
    }
    cout << ans << endl;
}
