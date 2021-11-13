#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_A"
#include "../../../template.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint1000000007;
int main() {
    ll n, k; cin >> n >> k;
    cout << mint(k).pow(n) << endl;
}
