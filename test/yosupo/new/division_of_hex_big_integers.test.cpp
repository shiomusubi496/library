#define PROBLEM "https://judge.yosupo.jp/problem/division_of_hex_big_integers"
#include "../../../other/template.hpp"
#include "../../../math/BigInteger.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        BigInteger a, b;
        scan_hex(scan, a); scan_hex(scan, b);
        auto [q, r] = divmod(a, b);
        print_hex(print, q);
        print << ' ';
        print_hex(print, r);
        print << '\n';
        print << flush;
    }
}
