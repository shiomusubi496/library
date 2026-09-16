#define PROBLEM "https://judge.yosupo.jp/problem/aho_corasick"
#include "../../../other/template.hpp"
#include "../../../string/AhoCorasick.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    vector<string> S(N); scan >> S;
    AhoCorasick<'a', 'z'> ac;
    rep (i, N) ac.insert(S[i]);
    ac.build();
    prints(ac.size());
    rep (i, 1, ac.size()) prints(ac.get_par(i), ac.get_fail(i));
    vector<int> res(N);
    rep (i, N) res[i] = ac.get_node(S[i]);
    prints(res);
}
