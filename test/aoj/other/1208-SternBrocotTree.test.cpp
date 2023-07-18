#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1208"
#include "../../../other/template.hpp"
#include "../../../math/SternBrocotTree.hpp"
using namespace std;
using sbt = SternBrocotTree<ll>;
using rat = typename sbt::Rat;
int main() {
    ll p, n;
    while (scan >> p >> n, p != 0) {
        auto [l, r] = sbt::max_right([&](rat x) -> bool {
            ll n = x.get_num(), d = x.get_den();
            return n * n < p * d * d;
        }, n);
        print << r.get_num() << "/" << r.get_den() << " " << l.get_num() << "/" << l.get_den() << endl;
    }
}
