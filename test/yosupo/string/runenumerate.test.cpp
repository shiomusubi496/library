#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
#include "../../../other/template.hpp"
#include "../../../string/RunEnumerate.hpp"
using namespace std;
int main() {
    string S; scan >> S;
    auto v = run_enumerate(S);
    prints(v.size());
    for (auto p : v) prints(p);
}
