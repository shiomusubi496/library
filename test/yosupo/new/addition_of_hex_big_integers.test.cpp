#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_hex_big_integers"
#include "../../../other/template.hpp"
#include "../../../math/BigInteger.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        BigInteger a, b;
        scan_hex(scan, a); scan_hex(scan, b);
        print_hex(print, a + b);
        print << endl;
    }
}
