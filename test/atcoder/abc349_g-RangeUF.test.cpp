#define PROBLEM "https://atcoder.jp/contests/abc349/tasks/abc349_g"
#include "../../other/template.hpp"
#include "../../data-struct/unionfind/RangeParallelUnionFind.hpp"
using namespace std;

vector<int> solve_static(int N, vector<int> A) {
    vector<array<int, 3>> qs(N);
    rep (i, N) qs[i] = {(int)i - A[i], 2 * N - (int)i - 1 - A[i], 2 * A[i] + 1};
    auto uf = static_range_parallel_union_find(2 * N, qs);
    rep (i, N) uf.merge(i, 2 * N - 1 - i);
    vector<vector<int>> g(2 * N);
    rep (i, N) {
        if (i - A[i] == 0 || i + A[i] == N - 1) continue;
        int a = uf.find(i - A[i] - 1), b = uf.find(i + A[i] + 1);
        if (a == b) return {};
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int>> grp(2 * N);
    rep (i, 2 * N) grp[uf.find(i)].push_back(i);
    vector<int> res(2 * N, -1);
    rep (i, N) {
        if (res[i] != -1) continue;
        set<int> st;
        for (int j : g[uf.find(i)]) {
            if (res[j] != -1) st.insert(res[j]);
        }
        int cnt = 1;
        while (st.count(cnt)) ++cnt;
        for (int j : grp[uf.find(i)]) res[j] = cnt;
    }
    res.resize(N);
    return res;
}

vector<int> solve_dynamic(int N, vector<int> A) {
    RangeParallelUnionFind ruf(2 * N);
    rep (i, N) ruf.merge(i - A[i], 2 * N - 1 - i - A[i], 2 * A[i] + 1);
    auto uf = ruf.get_uf();
    rep (i, N) uf.merge(i, 2 * N - 1 - i);
    vector<vector<int>> g(2 * N);
    rep (i, N) {
        if (i - A[i] == 0 || i + A[i] == N - 1) continue;
        int a = uf.find(i - A[i] - 1), b = uf.find(i + A[i] + 1);
        if (a == b) return {};
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int>> grp(2 * N);
    rep (i, 2 * N) grp[uf.find(i)].push_back(i);
    vector<int> res(2 * N, -1);
    rep (i, N) {
        if (res[i] != -1) continue;
        set<int> st;
        for (int j : g[uf.find(i)]) {
            if (res[j] != -1) st.insert(res[j]);
        }
        int cnt = 1;
        while (st.count(cnt)) ++cnt;
        for (int j : grp[uf.find(i)]) res[j] = cnt;
    }
    res.resize(N);
    return res;
}

int main() {
    int N; scan >> N;
    vector<int> A(N); scan >> A;
    auto res1 = solve_static(N, A);
    auto res2 = solve_dynamic(N, A);
    assert(res1 == res2);
    if (res1.empty()) prints("No");
    else {
        prints("Yes");
        prints(res1);
    }
}
