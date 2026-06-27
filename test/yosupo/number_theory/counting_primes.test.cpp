#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include "../../../other/template.hpp"
#include "../../../math/num/LucyDP.hpp"
using namespace std;
int main() {
    ll n; scan >> n;
    prints(LucyDP(n));
}
