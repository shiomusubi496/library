#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_B"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/tree/ReRooting.hpp"
using namespace std;
int main() {
    int N; scan >> N;
    Graph<ll> G(N);
    rep (N - 1) {
        ll a, b, c; scan >> a >> b >> c;
        G.add_edge(a, b, c);
    }
    auto f = [&](ll x, auto e) {
        return x + e.cost;
    };
    ReRooting<Monoid::Max<ll>, ll, decltype(f)> rr(G, f, vector<ll>(N, 0));
    rep (i, N) print << rr[i] << endl;
}
