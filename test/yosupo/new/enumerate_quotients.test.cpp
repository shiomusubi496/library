#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_quotients"
#include "../../../other/template.hpp"
#include "../../../math/EnumerateQuotients.hpp"
using namespace std;
int main() {
    ll N; scan >> N;
    auto v = enumurate_quotients(N);
    v.pop_back();
    reverse(all(v));
    for (auto& x : v) x = N / x;
    prints(v.size());
    prints(v);
}
