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
        if (this->empty()) return {};
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
        FormalPowerSeries f(1, (*this)[0].inv());
        for (int m = 1; m < deg; m <<= 1) {
            FormalPowerSeries t = this->prefix(2 * m);
            f.resize(2 * m);
            FormalPowerSeries dft_f = f;
            number_theoretic_transform(t);
            number_theoretic_transform(dft_f);
            rep (i, 2 * m) t[i] *= dft_f[i];
            inverse_number_theoretic_transform(t);
            std::fill(t.begin(), t.begin() + m, T{0});
            number_theoretic_transform(t);
            rep (i, 2 * m) dft_f[i] *= t[i];
            inverse_number_theoretic_transform(dft_f);
            rep (i, m, 2 * m) f[i] = -dft_f[i];
        }
        return f.prefix(deg);
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
            res = res * 2 - (res * res * this->prefix(2 * m)).prefix(2 * m);
        }
        return res.prefix(deg);
    }
    FormalPowerSeries log(int deg = -1) const {
        assert(this->size() > 0 && (*this)[0] == 1);
        if (deg == -1) deg = this->size();
        return (diff().prefix(deg - 1) * inv(deg - 1)).prefix(deg - 1).integral();
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
    FormalPowerSeries exp(int deg = -1) const {
        assert(this->size() > 0 && (*this)[0] == 0);
        if (deg == -1) deg = this->size();
        FormalPowerSeries df = this->diff();
        FormalPowerSeries f(1, 1);
        FormalPowerSeries g(1, 1);
        FormalPowerSeries dft_f = f;
        number_theoretic_transform(dft_f);
        for (int m = 1; m < deg; m <<= 1) {
            dft_f.ntt_doubling(f);
            f.resize(2 * m);
            g.resize(2 * m);
            FormalPowerSeries dft_g = g;
            number_theoretic_transform(dft_g);
            FormalPowerSeries t = df.prefix(2 * m);
            number_theoretic_transform(t);
            rep (i, 2 * m) t[i] *= dft_f[i];
            inverse_number_theoretic_transform(t);
            std::fill(t.begin(), t.begin() + m - 1, T{0});
            number_theoretic_transform(t);
            rep (i, 2 * m) t[i] *= dft_g[i];
            inverse_number_theoretic_transform(t);
            std::fill(t.begin(), t.begin() + m - 1, T{0});
            t = t.prefix(2 * m - 1).integral();
            number_theoretic_transform(t);
            rep (i, 2 * m) t[i] *= dft_f[i];
            inverse_number_theoretic_transform(t);
            rep (i, m, 2 * m) f[i] = t[i];
            if (2 * m < deg) {
                dft_f = f;
                number_theoretic_transform(dft_f);
                FormalPowerSeries t = dft_f;
                rep (i, 2 * m) t[i] *= dft_g[i];
                inverse_number_theoretic_transform(t);
                std::fill(t.begin(), t.begin() + m, T{0});
                number_theoretic_transform(t);
                rep (i, 2 * m) t[i] *= dft_g[i];
                inverse_number_theoretic_transform(t);
                rep (i, m, 2 * m) g[i] = -t[i];
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
        if ((i128)d * k >= deg) {
            FormalPowerSeries res(deg);
            return res;
        }
        deg -= d * k;
        FormalPowerSeries res = (((*this >> d) / a).log(deg) * k).exp(deg);
        res *= a.pow(k);
        res <<= d * k;
        return res;
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
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
        FormalPowerSeries t = (*this >> d);
        T sq = sqrt_mod<T>(a.get());
        if (sq == -1) return {};
        FormalPowerSeries f(1, sq), g(1, 1 / sq), dft_f = f;
        number_theoretic_transform(dft_f);
        for (int m = 1; m < deg; m <<= 1) {
            dft_f.ntt_doubling(f);
            f.resize(2 * m);
            g.resize(2 * m);
            FormalPowerSeries dft_g = g;
            number_theoretic_transform(dft_g);
            FormalPowerSeries u = dft_f;
            rep (i, 2 * m) u[i] *= dft_f[i];
            FormalPowerSeries tx = t.prefix(2 * m);
            number_theoretic_transform(tx);
            rep (i, 2 * m) u[i] = (tx[i] - u[i]) * dft_g[i];
            inverse_number_theoretic_transform(u);
            rep (i, m, 2 * m) f[i] = u[i] / 2;
            if (2 * m < deg) {
                dft_f = f;
                number_theoretic_transform(dft_f);
                FormalPowerSeries u = dft_g;
                rep (i, 2 * m) u[i] *= dft_f[i];
                inverse_number_theoretic_transform(u);
                std::fill(u.begin(), u.begin() + m, T{0});
                number_theoretic_transform(u);
                rep (i, 2 * m) u[i] *= dft_g[i];
                inverse_number_theoretic_transform(u);
                rep (i, m, 2 * m) g[i] = -u[i];
            }
        }
        return f.prefix(deg) << (d >> 1);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && !is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
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
        FormalPowerSeries t = (*this >> d);
        T sq = sqrt_mod<T>(a.get());
        if (sq == -1) return {};
        FormalPowerSeries f(1, sq);
        for (int m = 1; m < deg; m <<= 1) {
            f = (f + t * f.inv(2 * m)).prefix(2 * m) / 2;
        }
        return f.prefix(deg) << (d >> 1);
    }
    FormalPowerSeries compose(FormalPowerSeries g, int deg = -1) const {
        if (this->empty()) return {};
        if (g.empty()) return {(*this)[0]};
        assert(g[0] == 0);
        int n = deg == -1 ? this->size() : deg;
        int m = 1 << (bitop::ceil_log2(
                          std::max<int>(1, std::sqrt(n / std::log2(n)))) +
                      1);
        FormalPowerSeries p = g.prefix(m), q = g >> m;
        p.shrink();
        q.shrink();
        int l = (n + m - 1) / m;
        std::vector<FormalPowerSeries> fs(this->size());
        rep (i, this->size()) fs[i] = FormalPowerSeries{(*this)[i]};
        FormalPowerSeries pd = p.diff();
        int z = 0;
        while (z < (int)pd.size() && pd[z] == T{0}) z++;
        if (z == (int)pd.size()) {
            FormalPowerSeries ans;
            rrep (i, l) {
                ans = ((ans * q) << m).prefix(n - i * m) +
                      FormalPowerSeries{(*this)[i]};
            }
            return ans;
        }
        pd = (pd >> z).inv(n);
        FormalPowerSeries t = p;
        for (int k = 1; fs.size() > 1; k <<= 1) {
            std::vector<FormalPowerSeries> nfs((fs.size() + 1) / 2);
            t.resize(1 << (bitop::ceil_log2(t.size()) + 1));
            number_theoretic_transform(t);
            rep (i, fs.size() / 2) {
                nfs[i] = std::move(fs[2 * i]);
                fs[2 * i + 1].resize(t.size());
                number_theoretic_transform(fs[2 * i + 1]);
                rep (j, t.size()) fs[2 * i + 1][j] *= t[j];
                inverse_number_theoretic_transform(fs[2 * i + 1]);
                if ((int)fs[2 * i + 1].size() > n) fs[2 * i + 1].resize(n);
                nfs[i] += fs[2 * i + 1];
            }
            if (fs.size() & 1) nfs.back() = std::move(fs.back());
            fs = std::move(nfs);
            if (fs.size() > 1) {
                rep (i, t.size()) t[i] *= t[i];
                inverse_number_theoretic_transform(t);
                if ((int)t.size() > n) t.resize(n);
            }
        }
        FormalPowerSeries fp = fs[0].prefix(n);
        FormalPowerSeries res = fp;
        int n2 = 1 << (bitop::ceil_log2(n) + 1);
        FormalPowerSeries qpow(n2);
        qpow[0] = 1;
        q.resize(n2);
        number_theoretic_transform(q);
        pd.resize(n2);
        number_theoretic_transform(pd);
        rep (i, 1, l) {
            if ((n - i * m) * 4 <= n2) {
                while ((n - i * m) * 4 <= n2) {
                    n2 /= 2;
                }
                inverse_number_theoretic_transform(q);
                q.resize(n - i * m);
                q.resize(n2);
                number_theoretic_transform(q);
                inverse_number_theoretic_transform(pd);
                pd.resize(n - i * m);
                pd.resize(n2);
                number_theoretic_transform(pd);
            }
            qpow.resize(n - i * m);
            qpow.resize(n2);
            number_theoretic_transform(qpow);
            rep (j, n2) qpow[j] *= q[j];
            inverse_number_theoretic_transform(qpow);
            qpow.resize(n - i * m);

            fp = fp.diff() >> z;
            fp.resize(n - i * m);
            fp.resize(n2);
            number_theoretic_transform(fp);
            rep (j, n2) fp[j] *= pd[j];
            inverse_number_theoretic_transform(fp);
            fp.resize(n - i * m);

            res += ((qpow * fp).prefix(n - i * m) * Comb::finv(i)) << (i * m);
        }
        return res;
    }
    FormalPowerSeries compinv(int deg = -1) const {
        assert(this->size() >= 2 && (*this)[0] == 0 && (*this)[1] != 0);
        if (deg == -1) deg = this->size();
        FormalPowerSeries fd = diff();
        FormalPowerSeries x{0, 1};
        FormalPowerSeries res{0, (*this)[1].inv()};
        for (int m = 2; m < deg; m <<= 1) {
            auto tmp = prefix(2 * m).compose(res);
            auto d = tmp.diff();
            auto gd = res.diff();
            res -=
                ((tmp - x) * (d.inv(2 * m) * gd).prefix(2 * m)).prefix(2 * m);
        }
        return res.prefix(deg);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
    FormalPowerSeries& ntt_doubling() {
        ntt_doubling_(*this);
        return *this;
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<
                 AlwaysTrue && is_ntt_friendly<T::get_mod()>::value>::type* =
                 nullptr>
    FormalPowerSeries& ntt_doubling(const std::vector<T>& b) {
        ntt_doubling_(*this, b);
        return *this;
    }
};

/**
 * @brief FormalPowerSeries(形式的冪級数)
 * @docs docs/math/poly/FormalPowerSeries.md
 * @see https://nyaannyaan.github.io/library/fps/formal-power-series.hpp
 */
