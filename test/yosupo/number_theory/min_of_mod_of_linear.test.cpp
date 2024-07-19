#define PROBLEM "https://judge.yosupo.jp/problem/min_of_mod_of_linear"
#include "../../../other/template.hpp"
#include "../../../math/LinearModMin.hpp"
using namespace std;
int main() {
    int T; scan >> T;
    rep (T) {
        ll N, M, A, B; scan >> N >> M >> A >> B;
        prints(linear_mod_min(A, B, M, N).second);
    }
}
