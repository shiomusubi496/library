#pragma once

#include "../../other/template.hpp"
#include "../convolution/Convolution.hpp"
#include "../SqrtMod.hpp"
#include "../Combinatorics.hpp"
#include "FormalPowerSeries.hpp"

template<class T> class SparseFPS : public std::vector<std::pair<int, T>> {
private:
    using Base = std::vector<std::pair<int, T>>;
    using FPS = FormalPowerSeries<T>;
    using Comb = Combinatorics<T>;

    void refine() {
        if (this->empty()) return;
        std::sort(this->begin(), this->end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        int p = -1;
        rep (i, this->size()) {
            if ((*this)[i].second != T{0}) {
                if (p >= 0 && (*this)[i].first == (*this)[p].first) {
                    (*this)[p].second += (*this)[i].second;
                }
                else {
                    (*this)[++p] = (*this)[i];
                }
            }
        }
        this->resize(p + 1);
    }

public:
    using Base::Base;
    SparseFPS(const Base& v) : Base(v) {}
    SparseFPS(Base&& v) : Base(std::move(v)) {}
    SparseFPS(const FPS& v) {
        rep (i, v.size())
            if (v[i] != T{0}) this->emplace_back(i, v[i]);
    }
    SparseFPS(FPS&& v) {
        rep (i, v.size())
            if (v[i] != T{0}) this->emplace_back(i, std::move(v[i]));
    }
    FPS fps(int deg = -1) const {
        if (deg == -1) {
            deg = 0;
            for (auto p : *this) chmax(deg, p.first + 1);
        }
        FPS res(deg);
        for (auto p : *this) {
            if (p.first < deg) res[p.first] += p.second;
        }
        return res;
    }

    SparseFPS& operator<<=(int n) {
        for (auto& p : *this) p.first += n;
        return *this;
    }
    SparseFPS& operator>>=(int n) {
        for (auto& p : *this) p.first -= n;
        this->erase(std::remove_if(all(*this),
                                   [](const auto& p) { return p.first < 0; }),
                    this->end());
        return *this;
    }
    friend SparseFPS operator<<(const SparseFPS& lhs, int rhs) {
        return SparseFPS(lhs) <<= rhs;
    }
    friend SparseFPS operator>>(const SparseFPS& lhs, int rhs) {
        return SparseFPS(lhs) >>= rhs;
    }
    SparseFPS& operator*=(const T& rhs) {
        for (auto& p : *this) p.second *= rhs;
        return *this;
    }
    friend SparseFPS operator*(const SparseFPS& lhs, const T& rhs) {
        return SparseFPS(lhs) *= rhs;
    }
    friend SparseFPS operator*(const T& lhs, const SparseFPS& rhs) {
        return SparseFPS(rhs) *= lhs;
    }
    SparseFPS& operator/=(const T& rhs) {
        T inv = T{1} / rhs;
        for (auto& p : *this) p.second *= inv;
        return *this;
    }
    friend SparseFPS operator/(const SparseFPS& lhs, const T& rhs) {
        return SparseFPS(lhs) /= rhs;
    }

    SparseFPS diff() const {
        SparseFPS res(*this);
        for (auto& p : res) {
            p.second *= p.first;
            --p.first;
        }
        res.erase(
            std::remove_if(all(res), [](const auto& p) { return p.first < 0; }),
            res.end());
        return res;
    }
    SparseFPS integral() const {
        int d = 0;
        for (auto& p : *this) chmax(d, p.first);
        Comb::init(d);
        SparseFPS res(*this);
        for (auto& p : res) {
            ++p.first;
            p.second *= Comb::inv(p.first);
        }
        return res;
    }

    friend FPS prod_sparse(FPS lhs, SparseFPS rhs, int deg = -1) {
        if (deg == -1) deg = lhs.size();
        lhs.resize(deg);
        rhs.refine();
        FPS res(deg);
        rep (i, deg) {
            for (auto p : rhs) {
                if (i + p.first < deg) res[i + p.first] += lhs[i] * p.second;
            }
        }
        return res;
    }

    friend FPS div_sparse(FPS lhs, SparseFPS rhs, int deg = -1) {
        if (deg == -1) deg = lhs.size();
        lhs.resize(deg);
        rhs.refine();
        FPS res(deg);
        T inv0 = T{1} / rhs[0].second;
        rep (i, deg) {
            res[i] = lhs[i] * inv0;
            for (auto p : rhs) {
                if (i + p.first < deg) lhs[i + p.first] -= res[i] * p.second;
            }
        }
        return res;
    }
    FPS inv(int deg) { return div_sparse(FPS{1}, *this, deg); }
    FPS log(int deg) {
        refine();
        assert(!this->empty() && (*this)[0].first == 0 &&
               (*this)[0].second == T{1});
        return div_sparse(this->diff().fps(deg - 1), *this, deg - 1).integral();
    }
    FPS exp(int deg) {
        refine();
        assert(this->empty() || (*this)[0].first != 0);
        Comb::init(deg - 1);
        SparseFPS f = diff();
        FPS res(deg);
        res[0] = T{1};
        rep (i, deg) {
            if (i != 0) res[i] *= Comb::inv(i);
            for (auto p : f) {
                if (i + p.first + 1 < deg) {
                    res[i + p.first + 1] += res[i] * p.second;
                }
            }
        }
        return res;
    }
    FPS pow(ll k, int deg) {
        refine();
        if (deg == 0) return {};
        if (k == 0) {
            FPS res(deg);
            res[0] = 1;
            return res;
        }
        if (this->empty()) return FPS(deg);
        int d = (*this)[0].first;
        T a = (*this)[0].second;
        if ((i128)(d)*k >= deg) return FPS(deg);
        if (k == 1) return fps(deg);
        if (k == 2) return prod_sparse(fps(deg), *this, deg);
        deg -= d * k;
        SparseFPS f = (*this >> d) / a;
        std::vector<std::tuple<int, T, T>> g;
        for (auto p : f) {
            if (p.first != 0) {
                g.emplace_back(p.first, p.second, p.first * p.second * k);
            }
        }
        Comb::init(deg - 1);
        FPS res(deg);
        res[0] = 1;
        rep (i, deg) {
            if (i != 0) res[i] *= Comb::inv(i);
            for (auto& p : g) {
                int a;
                T b, c;
                std::tie(a, b, c) = p;
                if (i + a < deg) {
                    res[i + a] += res[i] * c;
                    std::get<2>(p) -= b;
                }
            }
        }
        return (res * a.pow(k)) << (d * k);
    }
    FPS sqrt(int deg) {
        refine();
        if (this->empty()) return FPS(deg);
        int d = (*this)[0].first;
        T a = (*this)[0].second;
        if (d & 1) return {};
        if (d / 2 >= deg) return FPS(deg);
        deg -= d / 2;
        ll sq = sqrt_mod<T>(a.get());
        if (sq == -1) return {};
        SparseFPS f = (*this >> d) / a;
        std::vector<std::tuple<int, T, T>> g;
        for (auto p : f) {
            if (p.first != 0) {
                g.emplace_back(p.first, p.second, p.first * p.second / 2);
            }
        }
        Comb::init(deg - 1);
        FPS res(deg);
        res[0] = 1;
        rep (i, deg) {
            if (i != 0) res[i] *= Comb::inv(i);
            for (auto& p : g) {
                int a;
                T b, c;
                std::tie(a, b, c) = p;
                if (i + a < deg) {
                    res[i + a] += res[i] * c;
                    std::get<2>(p) -= b;
                }
            }
        }
        return (res * T{sq}) << (d / 2);
    }
};

/**
 * @brief SparseFormalPowerSeries(疎な形式的冪級数)
 * @docs docs/math/poly/SparseFormalPowerSeries.md
 */
