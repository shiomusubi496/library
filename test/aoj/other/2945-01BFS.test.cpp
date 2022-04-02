#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2945"
#include "../../../other/template.hpp"
#include "../../../graph/Graph.hpp"
#include "../../../graph/shortest-path/ZeroOneBFS.hpp"
using namespace std;
constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {1, 0, -1, 0};
int main() {
    int N;
    while (cin >> N) {
        if (N == 0) return 0;
        int A, B, C, D; cin >> A >> B >> C >> D;
        --A; --B; --C; --D;
        vector<pair<int, int>> E(N + 1);
        rep (i, N + 1) {
            cin >> E[i];
            --E[i].first; --E[i].second;
        }
        auto is_in = [&](int x, int y) -> bool {
            return A <= x && x <= C && B <= y && y <= D;
        };
        Graph<int> G(10000);
        rep (i, 100) rep (j, 100) {
            rep (k, 4) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || 100 <= nx || ny < 0 || 100 <= ny) continue;
                if (is_in(nx, ny)) G.add_edge(i * 100 + j, nx * 100 + ny, 0, true);
                else G.add_edge(i * 100 + j, nx * 100 + ny, 1, true);
            }
        }
        int ans = 0;
        rep (i, N) ans += ZeroOneBFS(G, E[i].first * 100 + E[i].second)[E[i + 1].first * 100 + E[i + 1].second];
        cout << ans << endl;
    }
}
