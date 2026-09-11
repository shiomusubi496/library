#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A"
#define ERROR 0.00000001
#include "../../../other/template.hpp"
#include "../../../geometry/Line.hpp"
using namespace std;
int main() {
    Point p0, p1; scan >> p0 >> p1;
    Line l(p0, p1);
    int q; scan >> q;
    rep (q) {
        Point p2; scan >> p2;
        printer << projection(l, p2) << endl;
    }
}
