#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"
#include "../../../other/template.hpp"
#include "../../../string/SuffixArray.hpp"
#include "../../../string/LCPArray.hpp"
using namespace std;
int main() {
    string S; scan >> S;
    auto sa = suffix_array(S);
    auto lcp = lcp_array(S, sa);
    int N = S.size();
    ll ans = (N - sa[0]);
    rep (i, N - 1) ans += (N - sa[i + 1]) - lcp[i];
    prints(ans);
}
