#define PROBLEM "https://judge.yosupo.jp/problem/majority_voting"
#include "../../../other/template.hpp"
#include "../../../other/monoid2.hpp"
#include "../../../data-struct/segment/SegmentTree.hpp"
#include "../../../data-struct/segment/BinaryIndexedTree.hpp"
using namespace std;
int main() {
    map<int, int> mp;
    vector<vector<tuple<int, int, int>>> memo;
    auto f = [&](int x) {
        if (mp.count(x) == 0) {
            mp[x] = memo.size();
            memo.emplace_back();
        }
        return mp[x];
    };
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    rep (i, N) memo[f(A[i])].emplace_back(i, 1, -1);
    vector<int> ans;
    SegmentTree<Monoid::Majority<int>> seg([&] {
        vector<pair<int, int>> res(N);
        rep (i, N) res[i] = {A[i], 1};
        return res;
    }());
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int k, v; scan >> k >> v;
            memo[f(A[k])].emplace_back(k, -1, -1);
            A[k] = v;
            memo[f(A[k])].emplace_back(k, 1, -1);
            seg.set(k, {v, 1});
        }
        else {
            int l, r; scan >> l >> r;
            int x = seg.prod(l, r).first;
            memo[f(x)].emplace_back(l, r, ans.size());
            ans.push_back(x);
        }
    }
    rep (i, N) memo[f(A[i])].emplace_back(i, -1, -1);
    BinaryIndexedTree<int> bit(N);
    for (auto v : memo) {
        for (auto [a, b, c] : v) {
            if (c == -1) bit.add(a, b);
            else {
                if (b - a >= bit.sum(a, b) * 2) ans[c] = -1;
            }
        }
    }
    for (int i : ans) prints(i);
}
