#define PROBLEM "https://yukicoder.me/problems/no/705"
#include "../../other/template.hpp"
#include "../../dp/OnlineOfflineDP.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    vector<ll> a(n); scan >> a;
    vector<ll> x(n), y(n); scan >> x >> y;
    auto cube = [&](ll x) { return x * x * x; };
    prints(online_offline_dp(n + 1, [&](int l, int r) {
        return cube(abs(x[l] - a[r - 1])) + cube(abs(y[l]));
    })[n]);
}
