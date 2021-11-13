#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"
#include "../../../template.hpp"
using namespace std;
int main() {
    int m, n; cin >> m >> n;
    cout << mod_pow(m, n, 1000000007) << endl;
}
