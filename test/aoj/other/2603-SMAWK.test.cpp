#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2603"
#include "../../../other/template.hpp"
#include "../../../dp/DivideAndConquerOptimization.hpp"
using namespace std;
int main() {
    int s, n, m; scan >> s >> n >> m;
    vector<int> x(s); scan >> x;
    vector<int> t(n);
    rep (i, n) {
        int a, b; scan >> a >> b;
        t[i] = a - x[b - 1];
    }
    sort(all(t));
    vector<int> R(n + 1);
    rep (i, n) R[i + 1] = R[i] + t[i];
    int ans1 = divide_and_conquer_optimization(m, n + 1, [&](int l, int r) {
        return (r - l) * t[r - 1] - (R[r] - R[l]);
    })[m][n];
    int ans2 = divide_and_conquer_optimization_monotone(m, n + 1, [&](int l, int r) {
        return (r - l) * t[r - 1] - (R[r] - R[l]);
    })[m][n];
    assert(ans1 == ans2);
    prints(ans1);
}
