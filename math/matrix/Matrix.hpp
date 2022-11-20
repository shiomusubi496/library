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
    static Matrix get_id(int sz) {
        Matrix res(sz, sz, T{0});
        rep (i, sz) res[i][i] = T{1};
        return res;
    }
    int height() const { return this->size(); }
    int width() const { return this->size() ? (*this)[0].size() : 0; }
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
    friend Matrix operator*(const Matrix& lhs, int rhs) {
        return Matrix(lhs) *= rhs;
    }
    Matrix pow(ll b) {
        Matrix a = *this, res = get_id(height());
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
};

/**
 * @brief Matrix(行列)
 * @docs docs/math/matrix/Matrix.md
 */
