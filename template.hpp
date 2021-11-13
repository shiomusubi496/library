#pragma once

#include<bits/stdc++.h>

#ifndef __COUNTER__
#define __COUNTER__ __LINE__
#endif

#define REP_SELECTER(a, b, c, d, e, ...) e
#define REP1_0(b, c) REP1_1(b, c)
#define REP1_1(b, c) for (ll REP_COUNTER_ ## c = 0; REP_COUNTER_ ## c < (ll)(b); ++ REP_COUNTER_ ## c)
#define REP1(b) REP1_0(b, __COUNTER__)
#define REP2(i, b) for (ll i = 0; i < (ll)(b); ++i)
#define REP3(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define REP4(i, a, b, c) for (ll i = (ll)(a); i < (ll)(b); i += (ll)(c))
#define rep(...) REP_SELECTER(__VA_ARGS__, REP4, REP3, REP2, REP1) (__VA_ARGS__)
#define RREP2(i, a) for (ll i = (ll)(a) - 1; i >= 0; --i)
#define RREP3(i, a, b) for (ll i = (ll)(a) - 1; i >= (ll)(b); --i)
#define RREP4(i, a, b, c) for (ll i = (ll)(a) - 1; i >= (ll)(b); i -= (ll)(c))
#define rrep(...) REP_SELECTER(__VA_ARGS__, RREP4, RREP3, RREP2) (__VA_ARGS__)
#define REPS2(i, b) for (ll i = 1; i <= (ll)(b); ++i)
#define REPS3(i, a, b) for (ll i = (ll)(a) + 1; i <= (ll)(b); ++i)
#define REPS4(i, a, b, c) for (ll i = (ll)(a) + 1; i <= (ll)(b); i += (ll)(c))
#define reps(...) REP_SELECTER(__VA_ARGS__, REPS4, REPS3, REPS2) (__VA_ARGS__)
#define RREPS2(i, a) for (ll i = (ll)(a); i > 0; --i)
#define RREPS3(i, a, b) for (ll i = (ll)(a); i > (ll)(b); --i)
#define RREPS4(i, a, b, c) for (ll i = (ll)(a); i > (ll)(b); i -= (ll)(c))
#define rreps(...) REP_SELECTER(__VA_ARGS__, RREPS4, RREPS3, RREPS2) (__VA_ARGS__)

#define all(v) (v).begin(), (v).end()

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using PLL = std::pair<ll, ll>;
template<class T> using prique = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T> constexpr T INF = std::numeric_limits<T>::max() / 2;
constexpr ll inf = INF<ll>;
constexpr ld EPS = 1e-8;
constexpr ld PI = 3.1415926535897932384626;

template<class T, class U> std::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& p) {
    return ost << p.first << ' ' << p.second;
}
template<class T, class U> std::istream& operator<<(std::istream& ist, std::pair<T, U>& p) {
    return ist >> p.first >> p.second;
}

template<class Container,
        std::enable_if_t<!std::is_same<Container, std::string>::value>* = nullptr>
auto operator<<(std::ostream& ost, const Container& cont)
        -> decltype(cont.begin(), cont.end(), ost)
{
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) {
        if (itr != cont.begin()) ost << ' ';
        ost << *itr;
    }
    return ost;
}
template<class Container,
        std::enable_if_t<!std::is_same<Container, std::string>::value>* = nullptr>
auto operator>>(std::istream& ist, Container& cont)
        -> decltype(cont.begin(), cont.end(), ist)
{
    for (auto itr = cont.begin(); itr != cont.end(); ++itr) ist >> *itr;
    return ist;
}

template<class T, class U> inline constexpr bool chmin(T &a, const U &b) noexcept {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T, class U> inline constexpr bool chmax(T &a, const U &b) noexcept {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline constexpr ll gcd(ll a, ll b) noexcept {
    while (b) {
        const ll c = a;
        a = b;
        b = c % b;
    }
    return a;
}
inline constexpr ll lcm(ll a, ll b) noexcept {
    return a / gcd(a, b) * b;
}

inline constexpr bool is_prime(ll N) noexcept {
    if (N <= 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
inline std::vector<ll> prime_factor(ll N) noexcept {
    std::vector<ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res.push_back(i);
            N /= i;
        }
    }
    if (N != 1) res.push_back(N);
    return res;
}

inline constexpr ll my_pow(ll a, ll b) noexcept {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}
inline constexpr ll mod_pow(ll a, ll b, ll mod) noexcept {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1) (res *= a) %= mod;
        b >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

PLL extGCD(ll a, ll b) noexcept {
    if (b == 0) return PLL{1, 0};
    PLL p = extGCD(b, a % b);
    std::swap(p.first, p.second);
    p.second -= p.first * (a / b);
    if (p.first < 0) {
        p.first += b;
        p.second -= a;
    }
    return p;
}
ll mod_inv(ll a, ll mod) noexcept {
    const PLL p = extGCD(a, mod);
    assert(p.first * a + p.second * mod == 1);
    return p.first;
}
PLL ChineseRemainder(ll b1, ll m1, ll b2, ll m2) noexcept {
    const PLL p = extGCD(m1, m2);
    const ll g = p.first * m1 + p.second * m2;
    const ll l = m1 / g * m2;
    if((b2 - b1) % g != 0) return PLL{-1, -1};
    const ll x = (b2 - b1) / g * p.first % (m2 / g);
    return {(x * m1 + b1 + l) % l, l};
}
PLL ChineseRemainders(const std::vector<ll>& b, const std::vector<ll>& m) noexcept {
    PLL res{0, 1};
    rep (i, b.size()) {
        res = ChineseRemainder(res.first, res.second, b[i], m[i]);
        if (res.first == -1) return res;
    }
    return res;
}

template<class F> class rec_lambda {
  private:
    F f;
  public:
    explicit constexpr rec_lambda(F&& f_) : f(std::forward<F>(f_)) {}
    template<class... Args> constexpr auto operator()(Args&&... args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};

template<class T, class Arg> constexpr std::vector<T> make_vec(int n, Arg&& arg) {
    return std::vector<T>(n, arg);
}
template<class T, class... Args> constexpr auto make_vec(int n, Args&&... args) {
    return std::vector<decltype(make_vec<T>(args...))>
               (n, make_vec<T>(std::forward<Args>(args)...));
}

inline constexpr int popcnt(ull x) {
#if __cplusplus >= 202002L
    return std::popcount(x);
#endif
    x = (x & 0x5555555555555555) + ((x >> 1 ) & 0x5555555555555555);
    x = (x & 0x3333333333333333) + ((x >> 2 ) & 0x3333333333333333);
    x = (x & 0x0f0f0f0f0f0f0f0f) + ((x >> 4 ) & 0x0f0f0f0f0f0f0f0f);
    x = (x & 0x00ff00ff00ff00ff) + ((x >> 8 ) & 0x00ff00ff00ff00ff);
    x = (x & 0x0000ffff0000ffff) + ((x >> 16) & 0x0000ffff0000ffff);
    return (x & 0x00000000ffffffff) + ((x >> 32) & 0x00000000ffffffff);
}

template<class T> class presser : public std::vector<T> {
  private:
    using Base = std::vector<T>;
  public:
    using Base::Base;
    presser(const std::vector<T>& vec) : Base(vec) {}
    void push(const std::vector<T>& vec) {
        int n = this->size();
        this->resize(n + vec.size());
        std::copy(vec.begin(), vec.end(), this->begin() + n);
    }
    int build() {
        std::sort(this->begin(), this->end());
        this->erase(std::unique(this->begin(), this->end()), this->end());
        return this->size();
    }
    int get_index(const T& val) const {
        return static_cast<int>(std::lower_bound(this->begin(), this->end(), val) - this->begin());
    }
    std::vector<int> pressed(const std::vector<T>& vec) const {
        std::vector<int> res(vec.size());
        rep (i, vec.size()) res[i] = this->get_index(vec[i]);
        return res;
    }
    void press(std::vector<T>& vec) const {
        static_assert(std::is_integral<T>::value);
        rep (i, vec.size()) vec[i] = this->get_index(vec[i]);
    }
};
