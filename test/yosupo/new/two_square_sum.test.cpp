#define PROBLEM "https://judge.yosupo.jp/problem/two_square_sum"
#include "../../../other/template.hpp"
#include "../../../math/num/TwoSquareSum.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        ll n; scan >> n;
        if (n == 0) {
            prints(1);
            prints(0, 0);
            continue;
        }
        auto res = two_square_sum(n);
        vector<pair<ll, ll>> ans;
        for (auto [a, b] : res) {
            rep (4) {
                swap(a, b);
                a = -a;
                if (a >= 0 && b >= 0) ans.emplace_back(a, b);
            }
        }
        prints(ans.size());
        for (auto p : ans) prints(p);
    }
}
