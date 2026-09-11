#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_F"
#define ERROR 0.000001
#include "../../../other/template.hpp"
#include "../../../geometry/Circle.hpp"
using namespace std;
int main() {
    Point p; scan >> p;
    Circle c; scan >> c;
    auto ps = tangent_points(c, p);
    sort(all(ps));
    printer << ps[0] << endl;
    printer << ps[1] << endl;
}
