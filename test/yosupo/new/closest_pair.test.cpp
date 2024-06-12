#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"
#include "../../../other/template.hpp"
#define GEOMETRY_REAL_TYPE ll
#include "../../../geometry/Polygon.hpp"
using namespace std;
int main() {
    int t; scan >> t;
    rep (t) {
        int n; scan >> n;
        vector<Point> ps(n); scan >> ps;
        auto [a, b] = closest_pair(ps);
        int ans0 = -1, ans1 = -1;
        rep (i, n) {
            if (a == ps[i] && ans0 == -1) ans0 = i;
            else if (b == ps[i] && ans1 == -1) ans1 = i;
        }
        prints(ans0, ans1);
    }
}
