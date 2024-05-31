#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"
#include "../../../other/template.hpp"
#include "../../../string/WildcardPatternMatching.hpp"
using namespace std;
int main() {
    string S, T; scan >> S >> T;
    auto res = wildcard_pattern_matching(S, T, '*', false);
    auto res2 = wildcard_pattern_matching(S, T, '*', true);
    assert(res == res2);
    rep (i, res.size()) print << res[i];
    print << endl;
}
