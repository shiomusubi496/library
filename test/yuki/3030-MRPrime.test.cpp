#define PROBLEM "https://yukicoder.me/problems/no/3030"
#include "../../other/template.hpp"
#include "../../math/num/MillerRabin.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    rep (n) {
        ull x; scan >> x;
        print << x << " " << is_prime_mr(x) << endl;
    }
}
