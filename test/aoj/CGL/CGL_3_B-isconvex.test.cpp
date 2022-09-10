#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_B"
#include "../../../other/template.hpp"
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    Polygon p(n); scan >> p;
    print << (is_convex(p, true) ? 1 : 0) << endl;
}
