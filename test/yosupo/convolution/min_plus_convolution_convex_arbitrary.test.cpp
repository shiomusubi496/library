#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"
#include "../../../other/template.hpp"
#include "../../../math/convolution/MinPlusConvolution.hpp"
using namespace std;
int main() {
    int n, m; scan >> n >> m;
    vector<int> a(n), b(m); scan >> a >> b;
    prints(min_plus_convolution(b, a));
}
