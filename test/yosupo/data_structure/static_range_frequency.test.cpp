#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/StaticRangeFrequency.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    StaticRangeFrequency<int> srf(A);
    rep (Q) {
        int l, r, x; scan >> l >> r >> x;
        print << srf.count(l, r, x) << endl;
    }
}
