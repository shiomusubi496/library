#pragma once

#include "../../other/template.hpp"
#include "Matrix.hpp"

template<class T> class LinearEquations {
private:
    Matrix<T> A;
    int n, m;
    bool is_solved = false;
    std::vector<T> solution;
    Matrix<T> solution_space;

public:
    LinearEquations() = default;
    LinearEquations(int n) : m(n) {}
    LinearEquations(const Matrix<T>& A_, bool sol = true)
        : A(A_), n(A.height()), m(A.width() - 1) {
        if (sol) solve();
    }
    LinearEquations(const Matrix<T>& A_, const std::vector<T>& b,
                    bool sol = true) {
        assert(A_.height() == (int)b.size());
        n = A_.height();
        m = A_.width();
        A = Matrix<T>(n, m + 1);
        rep (i, n) {
            rep (j, m) A[i][j] = A_[i][j];
            A[i][m] = b[i];
        }
        if (sol) solve();
    }
    void add_equation(const std::vector<T>& a, T b) {
        assert(!is_solved);
        assert(a.size() == m);
        A.push_back(a);
        A.back().push_back(b);
    }
    void add_equation(const std::vector<T>& a) {
        assert(!is_solved);
        assert(a.size() == m + 1);
        A.push_back(a);
    }
    bool solve() {
        assert(!is_solved);
        is_solved = true;
        A.gauss();
        int r = A.rank(true);
        if (r != 0 && std::count(all(A[r - 1]), T{0}) == m &&
            A[r - 1][m] != 0) {
            return false;
        }
        solution = std::vector<T>(m, T{0});
        solution_space = Matrix<T>(0, m);
        std::vector<int> p(m, -1);
        rep (i, r) {
            int j = 0;
            while (A[i][j] == 0) ++j;
            p[j] = i;
            solution[j] = A[i][m];
        }
        rep (i, m) {
            if (p[i] == -1) {
                std::vector<T> v(m, T{0});
                v[i] = T{1};
                rep (j, m) {
                    if (p[j] != -1) v[j] = -A[p[j]][i];
                }
                solution_space.push_back(std::move(v));
            }
        }
        return true;
    }
    bool has_solution() const {
        assert(is_solved);
        return solution.size() != 0;
    }
    int dimension() const {
        assert(is_solved);
        return solution_space.height();
    }
    std::vector<T> get_solution() const& {
        assert(is_solved);
        return solution;
    }
    std::vector<T> get_solution() && {
        assert(is_solved);
        return std::move(solution);
    }
    Matrix<T> get_solution_space() const& {
        assert(is_solved);
        return solution_space;
    }
    Matrix<T> get_solution_space() && {
        assert(is_solved);
        return std::move(solution_space);
    }
};

/**
 * @brief LinearEquations(線形方程式)
 * @docs docs/math/matrix/LinearEquations.md
 */