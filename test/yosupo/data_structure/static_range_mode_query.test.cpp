#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/StaticRangeMode.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    StaticRangeMode srm(A);
    rep (Q) {
        int l, r; scan >> l >> r;
        prints(srm.prod(l, r));
    }
}
