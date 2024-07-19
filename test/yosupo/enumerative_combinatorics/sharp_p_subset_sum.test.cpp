#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"
#include "../../../other/template.hpp"
#include "../../../math/SubsetSum.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int n, t; scan >> n >> t;
    vector<int> s(n); scan >> s;
    auto ans = subset_sum<mint>(s, t);
    ans.erase(ans.begin());
    prints(ans);
}
