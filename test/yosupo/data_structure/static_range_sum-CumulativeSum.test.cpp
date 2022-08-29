#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/CumulativeSum.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<ll> A(N); scan >> A;
    CumulativeSum<ll> CS(A);
    rep (Q) {
        int l, r; scan >> l >> r;
        print << CS.prod(l, r) << endl;
    }
}
