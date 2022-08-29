#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../../other/template.hpp"
using namespace std;
int main() {
    int T;
    scan >> T;
    rep (T) {
        ll a, b;
        scan >> a >> b;
        print << a + b << '\n';
    }
}
