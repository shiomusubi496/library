#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../../other/template.hpp"
#include "../../../data-struct/wavelet/WaveletMatrix.hpp"
using namespace std;
int main() {
    int n, q; scan >> n >> q;
    vector<int> A(n); scan >> A;
    WaveletMatrix<int> wm(A);
    rep (q) {
        int l, r, k; scan >> l >> r >> k;
        print << wm.kth_smallest(l, r, k) << endl;
    }
}
