#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A"
#include "../../../other/template.hpp"
#include "../../../geometry/Line.hpp"
using namespace std;
int main() {
    Point p0, p1; scan >> p0 >> p1;
    Line l(p0, p1);
    int q; scan >> q;
    rep (q) {
        Point p2; scan >> p2;
        print << projection(l, p2) << endl;
    }
}
