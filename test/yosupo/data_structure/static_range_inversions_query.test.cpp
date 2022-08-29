#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/BinaryIndexedTree.hpp"
#include "../../../data-struct/other/Mo.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    presser<int> ps(A); ps.build();
    ps.press(A);
    int M = ps.size();
    vector<pair<int, int>> B(Q); scan >> B;
    Mo mo(N, move(B));
    BinaryIndexedTree<int> bit(M);
    vector<ll> ans(Q);
    ll cur = 0;
    mo.build([&](int k) -> void {
        cur += bit.sum(0, A[k]);
        bit.add(A[k], 1);
    }, [&](int k) -> void {
        cur += bit.sum(A[k] + 1, M);
        bit.add(A[k], 1);
    }, [&](int k) -> void {
        cur -= bit.sum(0, A[k]);
        bit.add(A[k], -1);
    }, [&](int k) -> void {
        cur -= bit.sum(A[k] + 1, M);
        bit.add(A[k], -1);
    }, [&](int k) -> void {
        ans[k] = cur;
    });
    each_const (i : ans) print << i << endl;
}
