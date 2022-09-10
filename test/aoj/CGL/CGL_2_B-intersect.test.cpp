#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_B"
#include "../../../other/template.hpp"
#include "../../../geometry/Segment.hpp"
using namespace std;
int main() {
    int q; scan >> q;
    rep (q) {
        Segment s1, s2; scan >> s1 >> s2;
        if (is_intersect(s1, s2)) prints("1");
        else prints("0");
    }
}
