#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"
#include "../../../other/template.hpp"
#include "../../../math/Rational.hpp"
#include "../../../math/SternBrocotTree.hpp"
using namespace std;
using sbt = SternBrocotTree<ll>;
using rat = typename sbt::Rat;
int main() {
    int t; scan >> t;
    rep (t) {
        string q; scan >> q;
        if (q == "ENCODE_PATH") {
            rat a; scan >> a;
            auto res = sbt::encode_path(a);
            prints(res.size(), res);
        }
        else if (q == "DECODE_PATH") {
            int n; scan >> n;
            vector<pair<char, int>> path(n); scan >> path;
            prints(sbt::decode_path(path).get_pair());
        }
        else if (q == "LCA") {
            rat a, b; scan >> a >> b;
            prints(sbt::lca(a, b).get_pair());
        }
        else if (q == "ANCESTOR") {
            ll k; scan >> k;
            rat a; scan >> a;
            auto res = sbt::ancestor(a, k);
            if (res == -1) prints(-1);
            else prints(res.get_pair());
        }
        else if (q == "RANGE") {
            rat a; scan >> a;
            auto [x, y] = sbt::range(a);
            prints(x.get_pair(), y.get_pair());
        }
    }
}
