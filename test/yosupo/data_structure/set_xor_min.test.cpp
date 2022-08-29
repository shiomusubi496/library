#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../../../other/template.hpp"
#include "../../../data-struct/other/BinaryTrie.hpp"
using namespace std;
int main() {
    BinaryTrie<30> BT;
    int Q; scan >> Q;
    rep (Q) {
        int t; scan >> t;
        ull x; scan >> x;
        if (t == 0) {
            if (BT.count(x) == 0) BT.insert(x);
        }
        else if (t == 1) {
            if (BT.count(x) == 1) BT.erase(x);
        }
        else {
            BT.xor_all(x);
            print << BT.kth_element(0) << endl;
            BT.xor_all(x);
        }
    }
}
