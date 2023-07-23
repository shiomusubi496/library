#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_B"
#include "../../../other/template.hpp"
#include "../../../data-struct/other/MaxRectangle.hpp"
using namespace std;
int main() {
    int H, W; scan >> H >> W;
    vector<vector<bool>> A(H, vector<bool>(W));
    rep (i, H) rep (j, W) {
        int a; scan >> a;
        A[i][j] = a;
    }
    int ans = 0;
    max_rectangle(A, [&](int u, int l, int d, int r) {
        ans = max(ans, (d - u) * (r - l));
    });
    prints(ans);
}
