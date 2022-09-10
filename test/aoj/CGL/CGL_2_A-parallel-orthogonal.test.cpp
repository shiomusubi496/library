#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_A"
#include "../../../other/template.hpp"
#include "../../../geometry/Line.hpp"
using namespace std;
int main() {
    int q; scan >> q;
    rep (q) {
        Point p0, p1, p2, p3; scan >> p0 >> p1 >> p2 >> p3;
        Line l1(p0, p1), l2(p2, p3);
        if (is_parallel(l1, l2)) prints("2");
        else if (is_orthogonal(l1, l2)) prints("1");
        else prints("0");
    }
}
