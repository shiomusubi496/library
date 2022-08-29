#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_C"
#include "../../../other/template.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    int l = 1;
    rep (n) {
        int a; scan >> a;
        l = lcm(l, a);
    }
    print << l << endl;
}
