#pragma once

#include "../../other/template.hpp"

template<class T>
class AssignmentProblem {
private:
    T c;
    std::vector<T> X, Y;
    std::vector<int> P;

public:
    AssignmentProblem(std::vector<std::vector<T>> C) {
        int n = C.size();
        int m = C[0].size();
        assert(n >= m);
        C.insert(C.begin(), std::vector<T>(m + 1, 0));
        reps (i, n) C[i].insert(C[i].begin(), 0);
        ++n; ++m;
        std::vector<int> way(m);
        P.resize(m);
        X.resize(n); Y.resize(m);
        rep (i, 1, n) {
            P[0] = i;
            int j0 = 0;
            std::vector<T> cur(m, infinity<T>::max);
            std::vector<bool> vis(m, false);
            while (P[j0] != 0) {
                vis[j0] = true;
                int i0 = P[j0], j1 = 0;
                T d = infinity<T>::max;
                rep (j, 1, m) {
                    if (vis[j]) continue;
                    if (chmin(cur[j], C[i0][j] - X[i0] - Y[j])) way[j] = j0;
                    if (chmin(d, cur[j])) j1 = j;
                }
                rep (j, m) {
                    if (vis[j]) X[P[j]] += d, Y[j] -= d;
                    else cur[j] -= d;
                }
                j0 = j1;
            }
            do {
                P[j0] = P[way[j0]];
                j0 = way[j0];
            } while (j0 != 0);
        }
        X.erase(X.begin());
        Y.erase(Y.begin());
        P.erase(P.begin());
        rep (i, n - 1) --P[i];
        c = 0;
        rep (i, n - 1) c += X[i];
        rep (j, m - 1) c += Y[j];
    }
    T cost() const { return c; }
    std::vector<int> rev_assignment() const { return P; }
    std::vector<int> assignment() const {
        std::vector<int> res(X.size(), -1);
        rep (i, P.size()) res[P[i]] = i;
        return res;
    }
    std::vector<T> getX() const { return X; }
    std::vector<T> getY() const { return Y; }
};
