#pragma once

#include "../../other/template.hpp"

template<class T> class Matrix : public std::vector<std::vector<T>> {
private:
    using Base = std::vector<std::vector<T>>;

public:
    Matrix() = default;
    Matrix(int h, int w) : Base(h, std::vector<T>(w)) {}
    Matrix(int h, int w, const T& v) : Base(h, std::vector<T>(w, v)) {}
    Matrix(const Base& v) : Base(v) {}
    Matrix(Base&& v) : Base(std::move(v)) {}
    static Matrix get_identity(int sz) {
        Matrix res(sz, sz, T{0});
        rep (i, sz) res[i][i] = T{1};
        return res;
    }
    int height() const { return this->size(); }
    int width() const { return this->size() ? (*this)[0].size() : 0; }
    bool is_square() const { return height() == width(); }
    Matrix& operator+=(const Matrix& other) {
        rep (i, this->height()) {
            rep (j, this->width()) (*this)[i][j] += other[i][j];
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& other) {
        rep (i, this->height()) {
            rep (j, this->width()) (*this)[i][j] -= other[i][j];
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& other) {
        assert(this->width() == other.height());
        Matrix res(this->height(), other.width());
        rep (i, this->height()) {
            rep (k, other.height()) {
                rep (j, other.width())
                    res[i][j] += (*this)[i][k] * other[k][j];
            }
        }
        return *this = std::move(res);
    }
    Matrix& operator*=(T s) {
        rep (i, height()) {
            rep (j, width()) (*this)[i][j] *= s;
        }
        return *this;
    }
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
        return Matrix(lhs) += rhs;
    }
    friend Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
        return Matrix(lhs) -= rhs;
    }
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        return Matrix(lhs) *= rhs;
    }
    friend Matrix operator*(const Matrix& lhs, T rhs) {
        return Matrix(lhs) *= rhs;
    }
    friend Matrix operator*(int lhs, const Matrix& rhs) {
        return Matrix(rhs) *= lhs;
    }
    Matrix pow(ll b) {
        Matrix a = *this, res = get_identity(height());
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
    Matrix transpose() const {
        Matrix res(width(), height());
        rep (i, height()) {
            rep (j, width()) res[j][i] = (*this)[i][j];
        }
        return res;
    }
    friend Matrix gauss(Matrix mat) {
        int h = mat.height(), w = mat.width();
        int r = 0;
        rep (i, w) {
            int pivot = -1;
            rep (j, r, h) {
                if (mat[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) continue;
            swap(mat[pivot], mat[r]);
            const T s = mat[r][i];
            rep (j, i, w) mat[r][j] /= s;
            rep (j, h) {
                if (j == r) continue;
                const T s = mat[j][i];
                if (s == 0) continue;
                rep (k, i, w) mat[j][k] -= mat[r][k] * s;
            }
            ++r;
        }
    }
    Matrix& gauss() { return *this = gauss(std::move(*this)); }
    int rank(bool is_gaussed = false) const {
        if (!is_gaussed) return gauss(*this).rank(true);
        const int h = height(), w = width();
        int r = 0;
        rep (i, h) {
            while (r < w && (*this)[i][r] == 0) ++r;
            if (r == w) return i;
            ++r;
        }
        return h;
    }
};

/**
 * @brief Matrix(行列)
 * @docs docs/math/matrix/Matrix.md
 */
