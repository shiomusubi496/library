#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_G"
#include "../../../other/template.hpp"
#include "../../../math/ModInt.hpp"
#include "../../../math/StirlingNumber.hpp"
using namespace std;
using mint = modint1000000007;
int main() {
    int n, k; scan >> n >> k;
    prints(bell_number_fixed_n<mint>(n)[min(n, k)]);
}
