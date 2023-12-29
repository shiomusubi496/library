#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
#include "../../../other/template.hpp"
#include "../../../string/RollingHash.hpp"
using namespace std;
int main() {
    string T, P; scan >> T >> P;
    RollingHash RH;
    auto tr = RH.get_hash(T);
    auto pr = RH.get_hash(P);
    rep (i, T.size() - P.size() + 1) {
        if (tr.prod(i, i + P.size()) == pr.all_prod()) print << i << endl;
    }
}
