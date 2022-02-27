#define PROBLEM "https://yukicoder.me/problems/no/1435"
#include "../../other/template.hpp"
#include "../../data-struct/segment/SegmentTree.hpp"
using namespace std;
int main() {
    struct Mmm {
        typedef struct value_type {
            int m1, m2, M;
        } T;
        static T op(T a, T b) {
            int v[4] = {a.m1, a.m2, b.m1, b.m2};
            sort(all(v));
            return {v[0], v[1], max(a.M, b.M)};
        }
        static T id() {
            return {infinity<int>::value, infinity<int>::value, infinity<int>::mvalue};
        }
    };
    int N; cin >> N;
    vector<int> A(N); cin >> A;
    vector<typename Mmm::value_type> B(N);
    rep (i, N) {
        B[i].m1 = B[i].M = A[i];
        B[i].m2 = infinity<int>::value;
    }
    SegmentTree<Mmm> seg(B);
    ll ans1 = 0, ans2 = 0;
    rep (i, N) {
        ll idx = seg.max_right(i, [&](const auto& v) { return v.M <= v.m1 + v.m2; });
        ans1 += idx - i - 1;
    }
    reps (i, N) {
        ll idx = seg.min_left(i, [&](const auto& v) { return v.M <= v.m1 + v.m2; });
        ans2 += i - idx - 1;
    }
    assert(ans1 == ans2);
    cout << ans1 << endl;
}
