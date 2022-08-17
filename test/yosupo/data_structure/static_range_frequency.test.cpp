#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/StaticRangeFrequency.hpp"
using namespace std;
int main() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); cin >> A;
    StaticRangeFrequency<int> srf(A);
    rep (Q) {
        int l, r, x; cin >> l >> r >> x;
        cout << srf.count(l, r, x) << endl;
    }
}
