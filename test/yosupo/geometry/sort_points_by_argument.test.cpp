#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include "../../../other/template.hpp"
#define GEOMETRY_REAL_TYPE ll
#include "../../../geometry/All.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    vector<Point> ps(n); scan >> ps;
    sort(all(ps), [&](const Point& a, const Point& b) { return atan2((ld)a.y, (ld)a.x) < atan2((ld)b.y, (ld)b.x); });
    each_const (p : ps) print << p << endl;
}
