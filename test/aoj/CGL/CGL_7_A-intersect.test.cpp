#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_A"
#include "../../../other/template.hpp"
#include "../../../geometry/Circle.hpp"
using namespace std;
int main() {
    Circle c1, c2; scan >> c1 >> c2;
    cout << (int)relation(c1, c2) << endl;
}
