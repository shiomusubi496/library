#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C"
#include "../../../other/template.hpp"
#include "../../../data-struct/other/MaxRectangle.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    vector<int> A(N); scan >> A;
    ll ans = 0;
    max_rectangle_of_histogram(A, [&](int l, int r, int h) {
        ans = max(ans, (ll)h * (r - l));
    });
    prints(ans);
}
