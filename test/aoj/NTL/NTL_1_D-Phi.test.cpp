#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D"
#include "../../../other/template.hpp"
#include "../../../math/num/EulerPhi.hpp"
using namespace std;
int main() {
    ll N; scan >> N;
    printer << euler_phi(N) << endl;
}
