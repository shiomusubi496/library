#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C"
#include "../../../other/template.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    int ans = 0;
    rep (n) {
        int a; scan >> a;
        if (is_prime(a)) ans++;
    }
    print << ans << endl;
}
