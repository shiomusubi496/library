#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "../../../other/template.hpp"
#include "../../../math/PollardRho.hpp"
using namespace std;
int main() {
    int q; scan >> q;
    rep (q) {
        ll n; scan >> n;
        auto res = factorize(n);
        print << res.size() << " " << res << endl;
    }
}
