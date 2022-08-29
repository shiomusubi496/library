#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E"
#include "../../../other/template.hpp"
using namespace std;
int main() {
    int a, b; scan >> a >> b;
    PLL p = extGCD(a, b);
    if (p.first - p.second < (p.second + a) - (p.first - b)) print << p << endl;
    else print << p.first - b << ' ' << p.second + a << endl;
}
