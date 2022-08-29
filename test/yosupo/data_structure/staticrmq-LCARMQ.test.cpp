#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/LCARMQ.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    LCARMQ<int> RMQ(A);
    rep (Q) {
        int l, r; scan >> l >> r;
        print << RMQ.prod(l, r) << endl;
    }
}
