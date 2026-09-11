#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../../../other/template.hpp"
#include "../../../graph/other/TwoSatisfiability.hpp"
using namespace std;
int main() {
    string s;
    int N, M;
    scan >> s >> s >> N >> M;
    TwoSatisfiability SAT(N);
    rep (M) {
        int a, b; scan >> a >> b >> s;
        SAT.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
    }
    auto v = SAT.sat();
    if (v.size() == 0) printer << "s UNSATISFIABLE" << endl;
    else {
        printer << "s SATISFIABLE" << endl;
        printer << "v ";
        rep (i, N) printer << (v[i] ? i + 1 : -i - 1) << ' ';
        printer << 0 << endl;
    }
}
