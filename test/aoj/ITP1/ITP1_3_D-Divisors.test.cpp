#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"
#include "../../../other/template.hpp"
#include "../../../math/Divisor.hpp"
using namespace std;
int main() {
    ll a, b, c; cin >> a >> b >> c;
    cout << divisors(c) << endl;
    ll ans = 0;
    each_const (i : divisors(c)) {
        if (a <= i && i <= b) ++ans;
    }
    cout << ans << endl;
}
