#define PROBLEM "https://atcoder.jp/contests/arc070/tasks/arc070_c"
#include "../../other/template.hpp"
#include "../../data-struct/other/SlopeTrick.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    vector<PLL> A(N); scan >> A;
    SlopeTrick<ll> st;
    st.abs(A[0].first);
    rep (i, 1, N) {
        st.slide_min(A[i].first - A[i].second, A[i - 1].second - A[i - 1].first);
        st.abs(A[i].first);
    }
    prints(st.min());
}
