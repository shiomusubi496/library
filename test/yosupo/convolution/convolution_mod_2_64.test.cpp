#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_2_64"
#include "../../../other/template.hpp"
#include "../../../math/convolution/Karatsuba.hpp"
using namespace std;
int main() {
    int n, m; scan >> n >> m;
    vector<ull> a(n), b(m); scan >> a >> b;
    prints(karatsuba(a, b));
}
