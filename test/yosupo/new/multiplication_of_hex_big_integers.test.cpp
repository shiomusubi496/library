#define PROBLEM "https://judge.yosupo.jp/problem/multiplication_of_hex_big_integers"
#include "../../../other/template.hpp"
#include "../../../math/BigInteger.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        BigInteger a, b;
        scan_hex(scan, a); scan_hex(scan, b);
        print_hex(print, a * b);
        print << '\n';
    }
}
