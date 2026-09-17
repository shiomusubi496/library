#pragma once

#include "../other/template.hpp"
#include "ZAlgorithm.hpp"

std::vector<int> string_sort(const std::vector<std::string>& A) {
    const int n = A.size();
    std::vector<std::vector<int>> Z(n);
    rep (i, n) Z[i] = ZAlgorithm(A[i]);
    std::vector<int> P(n);
    std::iota(all(P), 0);
    sort(all(P), [&](int a, int b) {
        int x = A[a].size(), y = A[b].size();
        if (x < y) {
            rep (i, x) if (A[a][i] != A[b][i]) return A[a][i] < A[b][i];
            int z = Z[b][x];
            if (z < y - x) return A[b][z] < A[b][x + z];
            rep (i, x) if (A[b][y - x + i] != A[a][i]) return A[b][y - x + i] < A[a][i];
            return false;
        }
        if (x > y) {
            rep (i, y) if (A[a][i] != A[b][i]) return A[a][i] < A[b][i];
            int z = Z[a][y];
            if (z < x - y) return A[a][y + z] < A[a][z];
            rep (i, y) if (A[b][i] != A[a][x - y + i]) return A[b][i] < A[a][x - y + i];
            return false;
        }
        return A[a] < A[b];
    });
    return P;
}
