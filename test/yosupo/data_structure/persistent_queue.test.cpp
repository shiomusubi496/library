#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include "../../../other/template.hpp"
#include "../../../data-struct/other/PersistentQueue.hpp"
using namespace std;
int main() {
    int q; scan >> q;
    PersistentQueue<int> que;
    rep (q) {
        int a; scan >> a;
        if (a == 0) {
            int t, x; scan >> t >> x;
            que.push(t, x);
        }
        else {
            int t; scan >> t;
            prints(que.front(t));
            que.pop(t);
        }
    }
}
