#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_15_B"
#include "../../../other/template.hpp"
#include "../../../math/Rational.hpp"
using namespace std;
int main() {
    int N, W; cin >> N >> W;
    vector<Fraction> A(N); cin >> A;
    sort(rall(A));
    Fraction ans;
    each_const (f : A) {
        ans += min<ll>(W, f.get_den()) * f;
        W -= f.get_den();
        chmax(W, 0);
    }
    cout << fixed << setprecision(12) << ans << endl;
}
