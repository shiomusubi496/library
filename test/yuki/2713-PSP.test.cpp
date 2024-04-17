#define PROBLEM "https://yukicoder.me/problems/no/2713"
#include "../../other/template.hpp"
#include "../../graph/flow/ProjectSelectionProblem.hpp"
using namespace std;
int main() {
    int N, M; scan >> N >> M;
    ProjectSelectionProblem<ll> psp(N);
    vector<ll> A(N); scan >> A;
    rep (i, N) psp.add_cost_1(i, A[i]);
    vector<ll> B(M); scan >> B;
    rep (i, M) {
        int K; scan >> K;
        vector<int> C(K); scan >> C;
        rep (i, K) --C[i];
        psp.add_profit_all_1(C, B[i]);
    }
    prints(psp.max_profit().first);
}
