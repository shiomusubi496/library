#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_A"
#include "../../../other/template.hpp"
#include "../../../geometry/Circle.hpp"
using namespace std;
int main() {
    Point p, q;
    Real r, s;
    scan >> p >> r >> q >> s;
    Circle c1(p, r), c2(q, s);
    cout << (int)relation(c1, c2) << endl;
}
