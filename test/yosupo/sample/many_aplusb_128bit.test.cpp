#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
#include "../../../other/template.hpp"
using namespace std;
int main() {
    int T;
    scan >> T;
    rep (T) {
        i128 a, b;
        scan >> a >> b;
        print << a + b << '\n';
    }
}
