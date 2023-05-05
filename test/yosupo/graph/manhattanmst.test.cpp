#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/mst/ManhattanMST.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    vector<PLL> A(N); scan >> A;
    auto mst = ManhattanMST(A);
    prints(mst.get());
    for (auto e : mst.get_edges()) prints(e.from, e.to);
}
