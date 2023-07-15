#pragma once

#include "../../other/template.hpp"
#include "../convolution/Convolution.hpp"
#include "../Combinatorics.hpp"
#include "../SqrtMod.hpp"

template<class T> class FormalPowerSeries : public std::vector<T> {
private:
    using Base = std::vector<T>;
    using Comb = Combinatorics<T>;

public:
    using Base::Base;
    FormalPowerSeries(const Base& v) : Base(v) {}
    FormalPowerSeries(Base&& v) : Base(std::move(v)) {}

    FormalPowerSeries& shrink() {
        while (!this->empty() && this->back() == T{0}) this->pop_back();
        return *this;
    }

    T eval(T x) const {
        T res = 0;
        rrep (i, this->size()) {
            res *= x;
            res += (*this)[i];
        }
        return res;
    }

    FormalPowerSeries prefix(int deg) const {
        assert(0 <= deg);
        if (deg < (int)this->size()) {
            return FormalPowerSeries(this->begin(), this->begin() + deg);
        }
        FormalPowerSeries res(*this);
        res.resize(deg);
        return res;
    }

    FormalPowerSeries operator+() const { return *this; }
    FormalPowerSeries operator-() const {
        FormalPowerSeries res(this->size());
        rep (i, this->size()) res[i] = -(*this)[i];
        return res;
    }
    FormalPowerSeries& operator<<=(int n) {
        this->insert(this->begin(), n, T{0});
        return *this;
    }
    FormalPowerSeries& operator>>=(int n) {
        this->erase(this->begin(),
                    this->begin() + std::min(n, (int)this->size()));
        return *this;
    }
    friend FormalPowerSeries operator<<(const FormalPowerSeries& lhs, int rhs) {
        return FormalPowerSeries(lhs) <<= rhs;
    }
    friend FormalPowerSeries operator>>(const FormalPowerSeries& lhs, int rhs) {
        return FormalPowerSeries(lhs) >>= rhs;
    }
    FormalPowerSeries& operator+=(const FormalPowerSeries& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        rep (i, rhs.size()) (*this)[i] += rhs[i];
        return *this;
    }
    FormalPowerSeries& operator-=(const FormalPowerSeries& rhs) {
        if (this->size() < rhs.size()) this->resize(rhs.size());
        rep (i, rhs.size()) (*this)[i] -= rhs[i];
        return *this;
    }
    friend FormalPowerSeries operator+(const FormalPowerSeries& lhs,
                                       const FormalPowerSeries& rhs) {
        return FormalPowerSeries(lhs) += rhs;
    }
    friend FormalPowerSeries operator-(const FormalPowerSeries& lhs,
                                       const FormalPowerSeries& rhs) {
        return FormalPowerSeries(lhs) -= rhs;
    }
    friend FormalPowerSeries operator*(const FormalPowerSeries& lhs,
                                       const FormalPowerSeries& rhs) {
        return FormalPowerSeries(convolution(lhs, rhs));
    }
    FormalPowerSeries& operator*=(const FormalPowerSeries& rhs) {
        return *this = *this * rhs;
    }
    FormalPowerSeries& operator*=(const T& rhs) {
        rep (i, this->size()) (*this)[i] *= rhs;
        return *this;
    }
    friend FormalPowerSeries operator*(const FormalPowerSeries& lhs,
                                       const T& rhs) {
        return FormalPowerSeries(lhs) *= rhs;
    }
    friend FormalPowerSeries operator*(const T& lhs,
                                       const FormalPowerSeries& rhs) {
        return FormalPowerSeries(rhs) *= lhs;
    }
    FormalPowerSeries& operator/=(const T& rhs) {
        rep (i, this->size()) (*this)[i] /= rhs;
        return *this;
    }
    friend FormalPowerSeries operator/(const FormalPowerSeries& lhs,
                                       const T& rhs) {
        return FormalPowerSeries(lhs) /= rhs;
    }

    FormalPowerSeries rev() const {
        FormalPowerSeries res(*this);
        std::reverse(all(res));
        return res;
    }

    friend FormalPowerSeries div(FormalPowerSeries lhs, FormalPowerSeries rhs) {
        lhs.shrink();
        rhs.shrink();
        if (lhs.size() < rhs.size()) {
            return FormalPowerSeries{};
        }
        int n = lhs.size() - rhs.size() + 1;
        if (rhs.size() <= 32) {
            FormalPowerSeries res(n);
            T iv = rhs.back().inv();
            rrep (i, n) {
                T d = lhs[i + rhs.size() - 1] * iv;
                res[i] = d;
                rep (j, rhs.size()) lhs[i + j] -= d * rhs[j];
            }
            return res;
        }
        return (lhs.rev().prefix(n) * rhs.rev().inv(n)).prefix(n).rev();
    }
    friend FormalPowerSeries operator%(FormalPowerSeries lhs,
                                       FormalPowerSeries rhs) {
        lhs.shrink();
        rhs.shrink();
        if (lhs.size() < rhs.size()) {
            return lhs;
        }
        int n = lhs.size() - rhs.size() + 1;
        if (rhs.size() <= 32) {
            T iv = rhs.back().inv();
            rrep (i, n) {
                T d = lhs[i + rhs.size() - 1] * iv;
                rep (j, rhs.size()) lhs[i + j] -= d * rhs[j];
            }
            return lhs.shrink();
        }
        return (lhs - div(lhs, rhs) * rhs).shrink();
    }
    friend std::pair<FormalPowerSeries, FormalPowerSeries>
    divmod(FormalPowerSeries lhs, FormalPowerSeries rhs) {
        lhs.shrink();
        rhs.shrink();
        if (lhs.size() < rhs.size()) {
            return {FormalPowerSeries{}, lhs};
        }
        int n = lhs.size() - rhs.size() + 1;
        if (rhs.size() <= 32) {
            FormalPowerSeries res(n);
            T iv = rhs.back().inv();
            rrep (i, n) {
                T d = lhs[i + rhs.size() - 1] * iv;
                res[i] = d;
                rep (j, rhs.size()) lhs[i + j] -= d * rhs[j];
            }
            return {res, lhs.shrink()};
        }
        FormalPowerSeries q = div(lhs, rhs);
        return {q, (lhs - q * rhs).shrink()};
    }
    FormalPowerSeries& operator%=(const FormalPowerSeries& rhs) {
        return *this = *this % rhs;
    }

    FormalPowerSeries diff() const {
        FormalPowerSeries res(this->size() - 1);
        rep (i, res.size()) res[i] = (*this)[i + 1] * (i + 1);
        return res;
    }
    FormalPowerSeries integral() const {
        FormalPowerSeries res(this->size() + 1);
        res[0] = 0;
        Comb::init(this->size());
        rep (i, this->size()) res[i + 1] = (*this)[i] * Comb::inv(i + 1);
        return res;
    }

    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
    FormalPowerSeries inv(int deg = -1) const {
        assert(this->size() > 0 && (*this)[0] != 0);
        if (deg == -1) deg = this->size();
        FormalPowerSeries res(1, (*this)[0].inv());
        for (int m = 1; m < deg; m <<= 1) {
            FormalPowerSeries f(2 * m);
            for (int i = 0; i < std::min(2 * m, (int)this->size()); i++)
                f[i] = (*this)[i];
            res.resize(2 * m);
            FormalPowerSeries dft = res;
            number_theoretic_transform(f);
            number_theoretic_transform(dft);
            rep (i, 2 * m) f[i] *= dft[i];
            inverse_number_theoretic_transform(f);
            std::fill(f.begin(), f.begin() + m, T{0});
            number_theoretic_transform(f);
            rep (i, 2 * m) dft[i] *= f[i];
            inverse_number_theoretic_transform(dft);
            rep (i, m, 2 * m) res[i] = -dft[i];
        }
        return res.prefix(deg);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && !is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
    FormalPowerSeries inv(int deg = -1) const {
        assert(this->size() > 0 && (*this)[0] != 0);
        if (deg == -1) deg = this->size();
        FormalPowerSeries res(1, (*this)[0].inv());
        for (int m = 1; m < deg; m <<= 1) {
            res = (res * 2 - (res * res * this->prefix(2 * m)).prefix(2 * m))
                      .prefix(2 * m);
        }
        return res.prefix(deg);
    }
    FormalPowerSeries log(int deg = -1) const {
        assert(this->size() > 0 && (*this)[0] == 1);
        if (deg == -1) deg = this->size();
        return (diff() * inv(deg)).prefix(deg - 1).integral();
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
    FormalPowerSeries exp(int deg = -1) const {
        assert(this->size() > 0 && (*this)[0] == 0);
        if (deg == -1) deg = this->size();
        FormalPowerSeries f(1, 1);
        FormalPowerSeries g(1, 1);
        FormalPowerSeries dft_f(1, 1);
        for (int m = 1; m < deg; m <<= 1) {
            FormalPowerSeries q = prefix(m).diff();
            q.resize(m);
            number_theoretic_transform(q);
            rep (i, m) q[i] *= dft_f[i];
            inverse_number_theoretic_transform(q);
            FormalPowerSeries s = f.diff();
            s.resize(m);
            rep (i, m) s[i] -= q[i];
            s.insert(s.begin(), (T)s.back());
            s.pop_back();
            FormalPowerSeries dft_g = g;
            s.resize(2 * m);
            dft_g.resize(2 * m);
            number_theoretic_transform(s);
            number_theoretic_transform(dft_g);
            rep (i, 2 * m) s[i] *= dft_g[i];
            inverse_number_theoretic_transform(s);
            FormalPowerSeries u =
                (prefix(2 * m) - (s.prefix(m) << (m - 1)).integral()) >> m;
            u.resize(2 * m);
            FormalPowerSeries dft_f_2 = f;
            dft_f_2.resize(2 * m);
            number_theoretic_transform(u);
            number_theoretic_transform(dft_f_2);
            rep (i, 2 * m) u[i] *= dft_f_2[i];
            inverse_number_theoretic_transform(u);
            f = f + (u.prefix(m) << m);
            if (2 * m < deg) {
                g.resize(2 * m);
                FormalPowerSeries dft_g_2 = g;
                FormalPowerSeries dft_f_2 = f;
                number_theoretic_transform(dft_g_2);
                number_theoretic_transform(dft_f_2);
                dft_f = dft_f_2;
                rep (i, 2 * m) dft_f_2[i] *= dft_g_2[i];
                inverse_number_theoretic_transform(dft_f_2);
                std::fill(dft_f_2.begin(), dft_f_2.begin() + m, T{0});
                number_theoretic_transform(dft_f_2);
                rep (i, 2 * m) dft_f_2[i] *= dft_g_2[i];
                inverse_number_theoretic_transform(dft_f_2);
                rep (i, m, 2 * m) g[i] = -dft_f_2[i];
            }
        }
        return f.prefix(deg);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && !is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
    FormalPowerSeries exp(int deg = -1) const {
        assert(this->size() > 0 && (*this)[0] == 0);
        if (deg == -1) deg = this->size();
        FormalPowerSeries res(1, 1);
        for (int m = 1; m < deg; m <<= 1) {
            res = (res * (prefix(2 * m) - res.log(2 * m)) + res).prefix(2 * m);
        }
        return res.prefix(deg);
    }
    FormalPowerSeries pow(ll k, int deg = -1) const {
        if (deg == -1) deg = this->size();
        if (deg == 0) return {};
        if (k == 0) {
            FormalPowerSeries res(deg);
            res[0] = 1;
            return res;
        }
        if (k == 1) return prefix(deg);
        if (k == 2) return (*this * *this).prefix(deg);
        T a;
        int d = -1;
        rep (i, this->size()) {
            if ((*this)[i] != 0) {
                a = (*this)[i];
                d = i;
                break;
            }
        }
        if (d == -1) {
            FormalPowerSeries res(deg);
            return res;
        }
        if ((__int128_t)(d)*k >= deg) {
            FormalPowerSeries res(deg);
            return res;
        }
        deg -= d * k;
        FormalPowerSeries res = (((*this >> d) / a).log(deg) * k).exp(deg);
        res *= a.pow(k);
        res <<= d * k;
        return res;
    }
    FormalPowerSeries sqrt(int deg = -1) const {
        if (deg == -1) deg = this->size();
        T a;
        int d = -1;
        rep (i, this->size()) {
            if ((*this)[i] != 0) {
                a = (*this)[i];
                d = i;
                break;
            }
        }
        if (d == -1) {
            FormalPowerSeries res(deg);
            return res;
        }
        if (d & 1) return {};
        deg -= (d >> 1);
        if (deg <= 0) {
            FormalPowerSeries res(deg);
            return res;
        }
        FormalPowerSeries f = (*this >> d);
        T sq = sqrt_mod<T>(a.get());
        if (sq == -1) return {};
        FormalPowerSeries g(1, sq);
        for (int m = 1; m < deg; m <<= 1) {
            g = (g + (f.prefix(2 * m) * g.inv(2 * m)).prefix(2 * m)) / 2;
        }
        g.resize(deg);
        return g << (d >> 1);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
    FormalPowerSeries& ntt_doubling() {
        ntt_doubling_(*this);
        return *this;
    }
};

/**
 * @brief FormalPowerSeries(形式的冪級数)
 * @docs docs/math/poly/FormalPowerSeries.md
 * @see https://nyaannyaan.github.io/library/fps/formal-power-series.hpp
 */
