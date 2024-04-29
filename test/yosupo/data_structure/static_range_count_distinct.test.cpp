#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/StaticRangeCountDistinct.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    vector<pair<int, int>> B(Q); scan >> B;
    auto ans = static_range_count_distinct(A, B);
    for (auto x : ans) prints(x);
}
