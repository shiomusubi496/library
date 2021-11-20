#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E"
#include "../../../other/template.hpp"
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    PLL p = extGCD(a, b);
    if (p.first - p.second < (p.second + a) - (p.first - b)) cout << p << endl;
    else cout << p.first - b << ' ' << p.second + a << endl;
}
