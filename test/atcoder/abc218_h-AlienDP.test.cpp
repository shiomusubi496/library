#define PROBLEM "https://atcoder.jp/contests/abc218/tasks/abc218_h"
#include "../../other/template.hpp"
#include "../../dp/AlienDP.hpp"
using namespace std;
int main() {
    int N, R; scan >> N >> R;
    vector<ll> A(N - 1); scan >> A;
    chmin(R, N - R);
    vector<ll> B(N);
    rep (i, N - 1) {
        B[i] += A[i];
        B[i + 1] += A[i];
    }
    prints(alien_dp_concave(-2e9, 2e9, R, [&](ll p) -> ll {
        ll v1 = 0, v2 = 0;
        rep (i, N) {
            ll n1 = v2 + B[i] - p, n2 = v1;
            chmax(v1, n1);
            chmax(v2, n2);
        }
        return max(v1, v2);
    }));
}
