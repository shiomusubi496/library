#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_C"
#define ERROR 0.00001
#include "../../../other/template.hpp"
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    Polygon p(n); scan >> p;
    int q; scan >> q;
    rep (q) {
        Point a, b; scan >> a >> b;
        print << area(polygon_cut(p, a, b)) << endl;
    }
}
