#define PROBLEM "https://yukicoder.me/problems/no/8030"
#include "../../other/template.hpp"
#include "../../math/num/MillerRabin.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    rep (n) {
        ull x; scan >> x;
        printer << x << " " << is_prime_mr(x) << endl;
    }
}
