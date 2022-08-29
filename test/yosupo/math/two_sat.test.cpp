#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../../../other/template.hpp"
#include "../../../graph/other/TwoSatisfiablitity.hpp"
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
    if (v.size() == 0) print << "s UNSATISFIABLE" << endl;
    else {
        print << "s SATISFIABLE" << endl;
        print << "v ";
        rep (i, N) print << (v[i] ? i + 1 : -i - 1) << ' ';
        print << 0 << endl;
    }
}
