#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_A"
#include "../../../other/template.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    print << N << ": " << prime_factor(N) << endl;
}
