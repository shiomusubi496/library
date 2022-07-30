#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../../other/template.hpp"
#include "../../data-struct/other/BinaryTrie.hpp"
using namespace std;
int main() {
    BinaryTrie BT;
    int Q; cin >> Q;
    rep (Q) {
        int t; cin >> t;
        ull x; cin >> x;
        if (t == 0) {
            if (BT.count(x) == 0) BT.insert(x);
        }
        else if (t == 1) {
            if (BT.count(x) == 1) BT.erase(x);
        }
        else {
            BT.xor_all(x);
            cout << BT.kth_element(0) << endl;
            BT.xor_all(x);
        }
    }
}
