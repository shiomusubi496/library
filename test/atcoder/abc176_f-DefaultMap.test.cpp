#define PROBLEM "https://atcoder.jp/contests/abc176/tasks/abc176_f"
#include "../../../library/other/template.hpp"
#include "../../../library/data-struct/other/DefaultMap.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    vector<int> A(3 * N); scan >> A;
    rep (i, 3 * N) --A[i];
    auto dp = make_vec<int>(N, N, -INF<int>);
    dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0;
    int ans = 0;
    vector<int> mx(N, -INF<int>); mx[A[0]] = mx[A[1]] = 0;
    rep (i, N - 1) {
        int a = A[i * 3 + 2], b = A[i * 3 + 3], c = A[i * 3 + 4];
        if (a == b && b == c) {
            ++ans;
            continue;
        }
        default_map<int, default_map<int, int>> mp(default_map<int, int>(-INF<int>));
        {
            int p = -1, q = -1;
            if (a == b) p = a, q = c;
            if (b == c) p = b, q = a;
            if (a == c) p = c, q = b;
            if (p != -1) {
                rep (k, N) chmax(mp[k][q], dp[k][p] + 1);
            }
        }
        {
            chmax(mp[b][c], dp[a][a] + 1);
            chmax(mp[a][c], dp[b][b] + 1);
            chmax(mp[a][b], dp[c][c] + 1);
        }
        rep (k, N) {
            chmax(mp[a][b], mx[k]);
            chmax(mp[a][c], mx[k]);
            chmax(mp[b][c], mx[k]);
        }
        rep (k, N) {
            chmax(mp[a][k], mx[k]);
            chmax(mp[b][k], mx[k]);
            chmax(mp[c][k], mx[k]);
        }
        for (const auto& [j, m] : mp) {
            for (const auto& [k, v] : m) {
                chmax(dp[j][k], v); chmax(dp[k][j], v);
                chmax(mx[j], v); chmax(mx[k], v);
            }
        }
    }
    ll res = 0;
    rep (i, N) rep (j, N) {
        chmax(res, dp[i][j]);
        if (i == j && i == A[3 * N - 1]) chmax(res, dp[i][j] + 1);
    }
    print << ans + res << endl;
}
