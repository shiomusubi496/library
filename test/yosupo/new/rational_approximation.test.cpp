#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"
#include "../../../other/template.hpp"
#include "../../../math/SternBrocotTree.hpp"
using namespace std;
using SBT = SternBrocotTree<int>;
using Rat = typename SBT::Rat;
int main() {
    int T; scan >> T;
    rep (T) {
        int N, X, Y; scan >> N >> X >> Y;
        Rat r(X, Y);
        auto [a, b] = SBT::max_right([&](auto x) { return x <= r; }, N);
        if (a == r) b = r;
        prints(a.get_pair(), b.get_pair());
    }
}
