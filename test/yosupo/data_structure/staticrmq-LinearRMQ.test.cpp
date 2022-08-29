#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../../other/template.hpp"
#include "../../../data-struct/segment/LinearRMQ.hpp"
using namespace std;
int main() {
    int N, Q; scan >> N >> Q;
    vector<int> A(N); scan >> A;
    LinearRMQ<Monoid::Min<int>> RMQ(A);
    rep (Q) {
        int l, r; scan >> l >> r;
        print << RMQ.prod(l, r) << endl;
    }
}
