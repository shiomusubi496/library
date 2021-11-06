#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A"
#include "../../template.hpp"
using namespace std;
int main() {
    int N; cin >> N;
    cout << N << ":" << prime_factor(N) << endl;
}
