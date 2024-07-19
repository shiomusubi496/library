#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include "../../../other/template.hpp"
#include "../../../math/KthRoot.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        ull a, k; scan >> a >> k;
        print << kth_root(a, k) << endl;
    }
}
