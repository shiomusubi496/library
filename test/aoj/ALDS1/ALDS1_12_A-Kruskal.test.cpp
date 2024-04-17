#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_A"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/Kruskal.hpp"
using namespace std;
int main() {
    int n; scan >> n;
    Edges<int> Ed;
    rep (i, n) {
        rep (j, n) {
            int a; scan >> a;
            if (a != -1) {
                Ed.emplace_back(i, j, a);
            }
        }
    }
    print << Kruskal(n, Ed).first << endl;
}
