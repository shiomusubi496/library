#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/SSegmentTree.hpp"
using namespace std;
struct Merge {
    using value_type = vector<int>;
    static value_type op(const value_type& a, const value_type& b) {
        value_type c; c.reserve(a.size() + b.size());
        merge(all(a), all(b), back_inserter(c));
        return c;
    }
    static value_type id() { return {}; }
};
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    SSegmentTree<Merge> seg([&] {
        vector<vector<int>> B(N);
        rep (i, N) B[i] = {A[i]};
        return B;
    }());
    rep (Q) {
        int l, r, k; scan >> l >> r >> k;
        int ok = 1e9, ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            int cnt = seg.prod<Monoid::Sum<int>>(l, r, [&](const vector<int>& v) -> int {
                return upper_bound(all(v), mid) - v.begin();
            });
            if (cnt > k) ok = mid;
            else ng = mid;
        }
        print << ok << endl;
    }
}
