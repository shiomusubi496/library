#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_B"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/Combinatorics.hpp"
using namespace std;
using mint = modint1000000007;
using comb = Combinatorics<mint>;
int main() {
    ll n, k; scan >> n >> k;
    print << comb::perm(k, n) << endl;
}
