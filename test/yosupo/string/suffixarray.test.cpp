#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "../../../other/template.hpp"
#include "../../../string/SuffixArray.hpp"
using namespace std;
int main() {
    string S; scan >> S;
    prints(suffix_array(S));
}
