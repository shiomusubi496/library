#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"
#include "../../../other/template.hpp"
#define GEOMETRY_REAL_TYPE ll
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        int N; scan >> N;
        vector<Point> p(N); scan >> p;
        auto q = convex_hull(p);
        prints(q.size());
        for (auto i : q) prints(i);
    }
}
