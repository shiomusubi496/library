#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_5_A"
#define ERROR 0.000001
#define GEOMETRY_EPS 1e-12
#include "../../../other/template.hpp"
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    vector<Point> p(n); scan >> p;
    auto ps = closest_pair(p);
    print << distance(ps.first, ps.second) << endl;
}
