#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D"
#include "../../template.hpp"
#include "../../math/EulerPhi.hpp"
using namespace std;
int main() {
    ll N; cin >> N;
    cout << euler_phi(N) << endl;
}
