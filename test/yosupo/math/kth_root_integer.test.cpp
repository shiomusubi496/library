#define PROBLEM "https://judge.yosupo.jp/problem/kth_root_integer"
#include "../../../other/template.hpp"
#include "../../../math/KthRoot.hpp"
using namespace std;
int main() {
    int T; cin >> T;
    rep (T) {
        ull a, k; cin >> a >> k;
        cout << kth_root(a, k) << endl;
    }
}
