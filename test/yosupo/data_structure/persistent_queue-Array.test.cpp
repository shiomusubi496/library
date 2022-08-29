#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "../../../other/template.hpp"
#include "../../../data-struct/other/PersistentArray.hpp"
using namespace std;
int main() {
    int q; scan >> q;
    PersistentArray<int> PA(1);
    rep (q) {
        int a; scan >> a;
        if (a == 0) {
            int t, x; scan >> t >> x;
            PA.push_back(x, t);
        }
        else {
            int t; scan >> t;
            int frt = PA.get(0, t);
            print << PA.get(frt + 1, t) << endl;
            PA.set(0, frt + 1, t);
        }
    }
}
