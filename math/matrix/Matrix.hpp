#pragma once

#include "../../other/template.hpp"

template<class T> class Matrix : public std::vector<std::vector<T>> {
  protected:
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
    int width() const { return (*this)[0].size(); }
    Matrix& operator+=(const Matrix& other) {
        rep (i, this->size()) {
            rep (j, (*this)[0].size()) (*this)[i][j] += other[i][j];
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& other) {
        rep (i, this->size()) {
            rep (j, (*this)[0].size()) (*this)[i][j] -= other[i][j];
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& other) {
        assert(this->width() == other.height());
        Matrix res(this->size(), other[0].size());
        rep (i, this->size()) {
            rep (k, other.size()) {
                rep (j, other[0].size()) res[i][j] += (*this)[i][k] * other[k][j];
            }
        }
        *this = std::move(res);
        return *this;
    }
    Matrix& operator*=(T s) {
        rep (i, this->size()) {
            rep (j, (*this)[0].size()) (*this)[i][j] *= s;
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
        Matrix a = *this, res = get_id(this->size());
        while (b) {
            if (b & 1) res *= a;
            a *= a;
            b >>= 1;
        }
        return res;
    }
};

/**
 * @brief Matrix(??????)
 * @docs docs/Matrix.md
 */
