#pragma once

#include "../../other/template.hpp"
#include "../ModInt.hpp"

template<class> class Matrix;

namespace internal {

using Mat2 = Matrix<bool>;

template<int> Mat2 prod_mod2_sub(const Mat2&, const Mat2&);
template<int> void gauss_mod2_sub(Mat2&);

} // namespace internal

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
        assert(this->height() == other.height() &&
               this->width() == other.width());
        rep (i, this->height()) {
            rep (j, this->width()) (*this)[i][j] += other[i][j];
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& other) {
        assert(this->height() == other.height() &&
               this->width() == other.width());
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
                rep (j, other.width()) res[i][j] += (*this)[i][k] * other[k][j];
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
    friend Matrix operator*(T lhs, const Matrix& rhs) {
        return Matrix(rhs) *= lhs;
    }
    Matrix pow(ll b) const {
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
    Matrix& gauss() {
        int h = height(), w = width();
        int r = 0;
        rep (i, w) {
            int pivot = -1;
            rep (j, r, h) {
                if ((*this)[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) continue;
            std::swap((*this)[pivot], (*this)[r]);
            const T s = (*this)[r][i], iv = T{1} / s;
            rep (j, i, w) (*this)[r][j] *= iv;
            rep (j, h) {
                if (j == r) continue;
                const T s = (*this)[j][i];
                if (s == 0) continue;
                rep (k, i, w) (*this)[j][k] -= (*this)[r][k] * s;
            }
            ++r;
        }
        return *this;
    }
    friend Matrix gauss(const Matrix& mat) { return Matrix(mat).gauss(); }
    int rank(bool is_gaussed = false) const {
        const int h = height(), w = width();
        if (!is_gaussed)
            return (h >= w ? Matrix(*this) : transpose()).gauss().rank(true);
        int r = 0;
        rep (i, h) {
            while (r < w && (*this)[i][r] == 0) ++r;
            if (r == w) return i;
            ++r;
        }
        return h;
    }
};

template<> class Matrix<bool> {
private:
    using T = bool;
    int h, w;
    std::vector<bool> v;

public:
    Matrix() = default;
    Matrix(int h, int w) : h(h), w(w), v(h * w, false) {}
    Matrix(int h, int w, const T& a) : h(h), w(w), v(h * w, a) {}
    Matrix(const std::vector<std::vector<bool>>& a) : h(a.size()), w(a[0].size()) {
        v.resize(a.size() * a[0].size());
        rep (i, a.size()) rep (j, a[0].size()) v[i * a[0].size() + j] = a[i][j];
    }
    auto get(int i, int j) { return v[i * w + j]; }
    auto get(int i, int j) const { return v[i * w + j]; }
    static Matrix get_identity(int sz) {
        Matrix res(sz, sz);
        rep (i, sz) res.get(i, i) = true;
        return res;
    }
    int height() const { return h; }
    int width() const { return w; }
    bool is_square() const { return height() == width(); }
    Matrix& operator+=(const Matrix& other) {
        assert(this->height() == other.height() &&
               this->width() == other.width());
        rep (i, this->height()) {
            rep (j, this->width()) {
                if (other.get(i, j)) get(i, j) = !get(i, j);
            }
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& other) {
        return (*this) += other;
    }
    Matrix& operator*=(const Matrix& other) {
        assert(this->width() == other.height());
        return *this = internal::prod_mod2_sub<1>(*this, other);
    }
    Matrix& operator*=(T s) {
        if (s == 0) {
            rep (i, height()) {
                rep (j, width()) get(i, j) = false;
            }
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
    friend Matrix operator*(T lhs, const Matrix& rhs) {
        return Matrix(rhs) *= lhs;
    }
    Matrix pow(ll b) const {
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
            rep (j, width()) res.get(j, i) = get(i, j);
        }
        return res;
    }
    Matrix& gauss() {
        internal::gauss_mod2_sub<1>(*this);
        return *this;
    }
    friend Matrix gauss(const Matrix& mat) { return Matrix(mat).gauss(); }
    int rank(bool is_gaussed = false) const {
        const int h = height(), w = width();
        if (!is_gaussed)
            return (h >= w ? Matrix(*this) : transpose()).gauss().rank(true);
        int r = 0;
        rep (i, h) {
            while (r < w && (*this).get(i, r) == 0) ++r;
            if (r == w) return i;
            ++r;
        }
        return h;
    }
};

namespace internal {

template<int len> Mat2 prod_mod2_sub(const Mat2& lhs, const Mat2& rhs) {
    const int h = lhs.height(), w = rhs.width(), m = lhs.width();
    if (len < m) return prod_mod2_sub<len << 1>(lhs, rhs);
    std::vector<std::bitset<len>> a(h), b(w);
    Mat2 res(h, w);
    rep (i, h) {
        rep (j, m) a[i][j] = lhs.get(i, j) != 0;
    }
    rep (i, m) {
        rep (j, w) b[j][i] = rhs.get(i, j) != 0;
    }
    rep (i, h) {
        rep (j, w) {
            res.get(i, j) = (a[i] & b[j]).count() & 1;
        }
    }
    return res;
}
template<> Mat2 prod_mod2_sub<1 << 30>(const Mat2&, const Mat2&) { return {}; }

template<int len> void gauss_mod2_sub(Mat2& a) {
    const int h = a.height(), w = a.width();
    if (len < w) return gauss_mod2_sub<len << 1>(a);
    std::vector<std::bitset<len>> b(h);
    rep (i, h) {
        rep (j, w) b[i][j] = a.get(i, j) != 0;
    }
    int r = 0;
    rep (i, w) {
        int pivot = -1;
        rep (j, r, h) {
            if (b[j][i] != 0) {
                pivot = j;
                break;
            }
        }
        if (pivot == -1) continue;
        std::swap(b[pivot], b[r]);
        rep (j, h) {
            if (j == r) continue;
            if (b[j][i] != 0) b[j] ^= b[r];
        }
        ++r;
    }
    rep (i, h) {
        rep (j, w) a.get(i, j) = (b[i][j] ? 1 : 0);
    }
}
template<> void gauss_mod2_sub<1 << 30>(Mat2&) {}

} // namespace internal

/**
 * @brief Matrix(行列)
 * @docs docs/math/matrix/Matrix.md
 */
