#define PROBLEM "https://atcoder.jp/contests/abc265/tasks/abc265_c"
#include "../../other/template.hpp"
#include "../../random/Timer.hpp"
using namespace std;
int main() {
    int H, W; scan >> H >> W;
    vector<string> A(H); scan >> A;
    int x = 0, y = 0;
    while (timer.elapsed() < 1950) {
        int nx = x, ny = y;
        switch (A[x][y]) {
            case 'L': ny--; break;
            case 'R': ny++; break;
            case 'U': nx--; break;
            case 'D': nx++; break;
        }
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
            print << x + 1 << " " << y + 1 << endl;
            return 0;
        }
        x = nx, y = ny;
    }
    prints("-1");
}
