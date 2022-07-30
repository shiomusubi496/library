#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../../../other/template.hpp"
#include "../../../graph/other/TwoSatisfiablitity.hpp"
using namespace std;
int main() {
    string s;
    int N, M;
    cin >> s >> s >> N >> M;
    TwoSatisfiability SAT(N);
    rep (M) {
        int a, b; cin >> a >> b >> s;
        SAT.add_clause(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
    }
    auto v = SAT.sat();
    if (v.size() == 0) puts("s UNSATISFIABLE");
    else {
        puts("s SATISFIABLE");
        cout << "v ";
        rep (i, N) cout << (v[i] ? i + 1 : -i - 1) << ' ';
        cout << 0 << endl;
    }
}
