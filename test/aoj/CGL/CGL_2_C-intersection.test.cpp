#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_C"
#define ERROR 0.00000001
#include "../../../other/template.hpp"
#include "../../../geometry/Segment.hpp"
using namespace std;
int main() {
    int q; scan >> q;
    rep (q) {
        Segment s1, s2; scan >> s1 >> s2;
        print << intersection(Line(s1), Line(s2)) << endl;
    }
}
