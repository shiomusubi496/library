#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2725"
#include "../../../other/template.hpp"
#include "../../../data-struct/cht/ConvexHullTrickAddMonotone.hpp"
using namespace std;
int main() {
    int N, T; cin >> N >> T;
    vector<array<ll, 3>> s(N); cin >> s;
    sort(s.begin(), s.end(), [](auto a, auto b) -> bool { return a[2] < b[2]; });
    vector<ConvexHullTrickAddMonotone<ll, true>> dp(T + 1);
    dp[0].add_line(0, 0);
    ll ans = 0;
    for (const auto& arr : s) {
        ll t = arr[0], p = arr[1], f = arr[2];
        rrep (i, T + 1) {
            if (dp[i].empty()) continue;
            if (i + t > T) continue;
            ll val = p + dp[i].inc_get_min(f);
            if (i != 0) val -= f * f;
            chmax(ans, val);
            dp[i + t].add_line(2 * f, val - f * f);
        }
    }
    cout << ans << endl;
}
