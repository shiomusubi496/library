#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0109"
#include "../../../other/template.hpp"
#include "../../../string/Parser.hpp"
using namespace std;
int main() {
    using parser = OperatorParser<int>;
    parser p(2);
    p.add_operator(0, "*", [](int a, int b) { return a * b; });
    p.add_operator(0, "/", [](int a, int b) { return a / b; });
    p.add_operator(1, "+", [](int a, int b) { return a + b; });
    p.add_operator(1, "-", [](int a, int b) { return a - b; });
    int q; scan >> q;
    rep (q) {
        string s; scan >> s;
        s.pop_back();
        prints(p.parse(s));
    }
}
