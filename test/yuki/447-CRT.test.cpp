#define PROBLEM "https://yukicoder.me/problems/447"
#include "../../other/template.hpp"
#include "../../math/ChineseRemainder.hpp"
using namespace std;
int main() {
    vector<ll> A(3), B(3);
    rep (i, 3) scan >> A[i] >> B[i];
    auto p = ChineseRemainder(A, B);
    if (p.first == 0) p.first += p.second;
    prints(p.first);
}
