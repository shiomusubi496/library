#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_C"
#define ERROR 0.000001
#include "../../../other/template.hpp"
#include "../../../geometry/Circle.hpp"
using namespace std;
int main() {
    Point p; scan >> p;
    Real r; scan >> r;
    const Circle c(p, r);
    int q; scan >> q;
    rep (q) {
        Point a, b; scan >> a >> b;
        const Line l(a, b);
        auto ps = intersections(c, l);
        sort(all(ps));
        if (ps.size() == 0) {
            assert(false);
        } else if (ps.size() == 1) {
            print << ps[0] << ' ' << ps[0] << endl;
        } else {
            print << ps[0] << ' ' << ps[1] << endl;
        }
    }
}
