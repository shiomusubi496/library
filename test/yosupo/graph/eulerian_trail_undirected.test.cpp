#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_undirected"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/other/EulerianTrail.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        int N, M; scan >> N >> M;
        Graph<int> G(N);
        rep (M) {
            int a, b; scan >> a >> b;
            G.add_edge(a, b);
        }
        EulerianTrail<int> et(G, false);
        if (et.has_trail()) {
            const auto& trail = et.get_trail();
            prints("Yes");
            print << (trail.empty() ? 0 : trail[0].from);
            rep (i, M) print << " " << trail[i].to;
            print << endl;
            rep (i, M) {
                print << trail[i].idx;
                if (i != M - 1) print << " ";
            }
            print << endl;
        }
        else {
            prints("No");
        }
    }
}
