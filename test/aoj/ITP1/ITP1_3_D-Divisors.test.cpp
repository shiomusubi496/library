#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"
#include "../../../other/template.hpp"
#include "../../../math/num/Divisors.hpp"
using namespace std;
int main() {
    ll a, b, c; scan >> a >> b >> c;
    ll ans = 0;
    for (const auto& i : divisors(c)) {
        if (a <= i && i <= b) ++ans;
    }
    print << ans << endl;
}
