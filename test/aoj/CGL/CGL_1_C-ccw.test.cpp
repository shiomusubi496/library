#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_C"
#include "../../../other/template.hpp"
#include "../../../geometry/Point.hpp"
using namespace std;
int main() {
    Point p0, p1; scan >> p0 >> p1;
    int q; scan >> q;
    rep (q) {
        Point p2; scan >> p2;
        int res = (int)ccw(p0, p1, p2);
        if (res == 1) prints("COUNTER_CLOCKWISE");
        if (res == -1) prints("CLOCKWISE");
        if (res == 2) prints("ONLINE_BACK");
        if (res == -2) prints("ONLINE_FRONT");
        if (res == 0) prints("ON_SEGMENT");
    }
}
