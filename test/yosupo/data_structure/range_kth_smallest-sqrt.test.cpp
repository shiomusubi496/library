#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../../../other/template.hpp"
#include "../../../other/monoid.hpp"
#include "../../../data-struct/segment/SqrtDecomposition.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    compressor<int> ps(A, true);
    ps.press(A);
    auto f = [&](vector<int>&& v) -> vector<int> {
        vector<int> A(ps.size());
        each_const (i : v) ++A[i];
        rep (i, ps.size() - 1) A[i + 1] += A[i];
        return A;
    };
    SqrtDecomposition<int, decltype(f)> sd(A, f);
    rep (Q) {
        int l, r, k; scan >> l >> r >> k;
        int ok = ps.size() - 1, ng = -1;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            auto g = [&](int x) -> int {
                return x <= mid;
            };
            auto h = [&](const vector<int>& v) -> int {
                return v[mid];
            };
            int cnt = sd.prod<Monoid::Sum<int>>(l, r, g, h);
            if (cnt > k) ok = mid;
            else ng = mid;
        }
        print << ps[ok] << endl;
    }
}
