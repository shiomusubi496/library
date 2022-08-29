#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"
#include "../../../other/template.hpp"
using namespace std;
int main() {
    int m, n; scan >> m >> n;
    print << mod_pow(m, n, 1000000007) << endl;
}
