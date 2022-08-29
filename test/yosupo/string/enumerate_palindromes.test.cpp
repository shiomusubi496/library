#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "../../../other/template.hpp"
#include "../../../string/Manacher.hpp"
using namespace std;
int main() {
    string S; scan >> S;
    print << ManacherEven(S) << endl;
}
