#define PROBLEM "https://yukicoder.me/problems/1601"
#include "../../other/template.hpp"
#include "../../data-struct/other/RangeSet.hpp"
using namespace std;
int main() {
    ll D, Q; scan >> D >> Q;
    RangeSet st;
    ll ans = 0;
    rep (Q) {
        ll a, b; scan >> a >> b;
        st.insert(a, b + 1);
        auto p = st.find(a);
        chmax(ans, p.second - p.first);
        print << ans << endl;
    }
}
