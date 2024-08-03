#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include "../../../other/template.hpp"
#include "../../../graph/flow/AssignmentProblem.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    vector<vector<ll>> C(n, vector<ll>(n)); scan >> C;
    AssignmentProblem<ll> ap(C);
    prints(ap.cost());
    prints(ap.assignment());
}
