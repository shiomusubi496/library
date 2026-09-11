#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"
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
            G.add_edge(a, b, true);
        }
        EulerianTrail<int> et(G, true);
        if (et.has_trail()) {
            const auto& trail = et.get_trail();
            prints("Yes");
            printer << (trail.empty() ? 0 : trail[0].from);
            rep (i, M) printer << " " << trail[i].to;
            printer << endl;
            rep (i, M) {
                printer << trail[i].idx;
                if (i != M - 1) printer << " ";
            }
            printer << endl;
        }
        else {
            prints("No");
        }
    }
}
