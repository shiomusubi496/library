#define PROBLEM "https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../data-struct/2D/StaticRectangleAddRectangleSum.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N, Q; scan >> N >> Q;
    vector<pair<array<ll, 4>, mint>> A(N); scan >> A;
    vector<array<ll, 4>> B(Q); scan >> B;
    auto ans = static_rectangle_add_rectangle_sum(A, B);
    for (auto x : ans) prints(x);
}
