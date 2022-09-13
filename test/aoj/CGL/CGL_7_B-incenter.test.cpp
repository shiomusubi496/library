#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_B"
#define ERROR 0.000001
#include "../../../other/template.hpp"
#include "../../../geometry/Triangle.hpp"
using namespace std;
int main() {
    Triangle t; scan >> t;
    print << t.incenter() << ' ' << t.inradius() << endl;
}
