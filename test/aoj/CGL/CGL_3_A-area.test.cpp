#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_A"
#include "../../../other/template.hpp"
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    Polygon p(n); scan >> p;
    printer << setprec(1) << area(p) << endl;
}
