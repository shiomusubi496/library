#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include "../../../other/template.hpp"
#include "../../../math/FloorSum.hpp"
int main() {
    int t; scan >> t;
    while (t--) {
        ll n, m, a, b; scan >> n >> m >> a >> b;
        print << floor_sum(n, m, a, b) << endl;
    }
}
