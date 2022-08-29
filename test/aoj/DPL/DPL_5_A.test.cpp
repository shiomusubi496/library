#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_A"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint1000000007;
int main() {
    ll n, k; scan >> n >> k;
    print << mint(k).pow(n) << endl;
}
