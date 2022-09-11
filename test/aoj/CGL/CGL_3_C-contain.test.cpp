#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_C"
#include "../../../other/template.hpp"
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    Polygon p(n); scan >> p;
    int q; scan >> q;
    rep (q) {
        Point a; scan >> a;
        print << (contains(p, a) ? 1 : 0) + (contains(p, a, false) ? 1 : 0) << endl;
    }
}
