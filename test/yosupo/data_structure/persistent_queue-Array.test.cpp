#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "../../../other/template.hpp"
#include "../../../data-struct/other/PersistentArray.hpp"
using namespace std;
int main() {
    int q; cin >> q;
    PersistentArray<int> PA(1);
    rep (q) {
        int a; cin >> a;
        if (a == 0) {
            int t, x; cin >> t >> x;
            PA.push_back(x, t);
        }
        else {
            int t; cin >> t;
            int frt = PA.get(0, t);
            cout << PA.get(frt + 1, t) << endl;
            PA.set(0, frt + 1, t);
        }
    }
}
