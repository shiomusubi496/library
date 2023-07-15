#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"
#include "../../../other/template.hpp"
#include "../../../math/StirlingNumber.hpp"
#include "../../../math/ModInt.hpp"
using namespace std;
using mint = modint998244353;
int main() {
    int N; scan >> N;
    prints(partition_number<mint>(N));
}
