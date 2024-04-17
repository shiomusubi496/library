#define PROBLEM "https://yukicoder.me/problems/no/119"
#include "../../other/template.hpp"
#include "../../graph/flow/KProjectSelectionProblem.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    KProjectSelectionProblem<ll> psp(N, 3);
    rep (i, N) {
        ll b, c; scan >> b >> c;
        psp.add_profit(i, {c, 0, b});
    }
    int M; scan >> M;
    rep (M) {
        int x, y; scan >> x >> y;
        psp.add_cost(x, y, {{0, 0, 0}, {0, 0, 0}, {inf, 0, 0}});
    }
    prints(psp.max_profit().first);
}
