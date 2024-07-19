#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_primes"
#include "../../../other/template.hpp"
#include "../../../math/PrimeFactor.hpp"
using namespace std;
int main() {
    int N, A, B; scan >> N >> A >> B;
    auto v = IsPrime(N).get_primes();
    vector<int> ans; ans.reserve(v.size());
    rep (i, B, v.size(), A) ans.push_back(v[i]);
    print << v.size() << " " << ans.size() << endl;
    prints(ans);
}
