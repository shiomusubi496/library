#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_G"
#define ERROR 0.000001
#include "../../../other/template.hpp"
#include "../../../geometry/Circle.hpp"
using namespace std;
int main() {
    Circle c1, c2; scan >> c1 >> c2;
    auto ps = common_tangents(c1, c2);
    sort(all(ps));
    for (const auto& p : ps) print << p << endl;
}
