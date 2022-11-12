#define PROBLEM "https://yukicoder.me/problems/448"
#include "../../other/template.hpp"
#include "../../math/ChineseRemainder.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    vector<ll> b(n), m(n);
    rep (i, n) scan >> b[i] >> m[i];
    auto res = Garner(b, m, 1000000007);
    if (count(all(b), 0) == n) prints(res.second);
    else prints(res.first);
}
