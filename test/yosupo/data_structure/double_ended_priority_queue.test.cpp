#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include "../../../other/template.hpp"
#include "../../../data-struct/heap/IntervalHeap.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> S(N); scan >> S;
    IntervalHeap<int> que(S);
    rep (Q) {
        int t; scan >> t;
        if (t == 0) {
            int x; scan >> x;
            que.push(x);
        }
        else if (t == 1) {
            prints(que.min());
            que.pop_min();
        }
        else {
            prints(que.max());
            que.pop_max();
        }
    }
}
