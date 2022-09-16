#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_E"
#define ERROR 0.000001
#include "../../../other/template.hpp"
#include "../../../geometry/Circle.hpp"
using namespace std;
int main() {
    Circle c1, c2; scan >> c1 >> c2;
    auto ps = intersections(c1, c2);
    sort(all(ps));
    if (ps.size() == 0) {
        assert(false);
    } else if (ps.size() == 1) {
        print << ps[0] << ' ' << ps[0] << endl;
    } else {
        print << ps[0] << ' ' << ps[1] << endl;
    }
}
