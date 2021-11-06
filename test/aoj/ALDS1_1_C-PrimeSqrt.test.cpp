#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C"
#include "../../template.hpp"
using namespace std;
int main() {
    int n; cin >> n;
    int ans = 0;
    rep (n) {
        int a; cin >> a;
        if (is_prime(a)) ans++;
    }
    cout << ans << endl;
}
