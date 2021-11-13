#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_E"
#include "../../../template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/Combinatorics.hpp"
using namespace std;
using mint = modint1000000007;
using comb = ModCombinatorics<mint>;
int main() {
    ll n, k; cin >> n >> k;
    cout << comb::comb(k, n) << endl;
}
