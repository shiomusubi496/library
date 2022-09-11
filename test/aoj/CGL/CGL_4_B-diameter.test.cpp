#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_B"
#define ERROR 0.000001
#include "../../../other/template.hpp"
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    Polygon p(n); scan >> p;
    print << diameter(p) << endl;
}
