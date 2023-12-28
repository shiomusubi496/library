#define PROBLEM "https://judge.yosupo.jp/problem/lyndon_factorization"
#include "../../../other/template.hpp"
#include "../../../string/LyndonFactorization.hpp"
using namespace std;
int main() {
    string s; scan >> s;
    prints(lyndon_factorization(s));
}
