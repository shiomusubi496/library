#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_A"
#define GEOMETRY_REAL_TYPE ll
#include "../../../other/template.hpp"
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    std::vector<Point> p(n); scan >> p;
    auto ch = convex_hull(p, true);
    int itr = min_element(all(ch), [](const Point& a, const Point& b) {
        return cmp(a.y, b.y) == 0 ? cmp(a.x, b.x) < 0 : cmp(a.y, b.y) < 0;
    }) - ch.begin();
    rep (i, ch.size()) {
        print << ch[(itr + i) % ch.size()] << endl;
    }
}
