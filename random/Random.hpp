#pragma once

#include "../other/template.hpp"

template<class Engine> class Random {
private:
    Engine rnd;

public:
    using result_type = typename Engine::result_type;
    Random() : Random(std::random_device{}()) {}
    Random(result_type seed) : rnd(seed) {}
    result_type operator()() { return rnd(); }
    result_type min() const { return rnd.min(); }
    result_type max() const { return rnd.max(); }
    template<class IntType = ll> IntType uniform(IntType l, IntType r) {
        static_assert(std::is_integral<IntType>::value,
                      "template argument must be an integral type");
        assert(l <= r);
        return std::uniform_int_distribution<IntType>{l, r}(rnd);
    }
    template<class RealType = double>
    RealType uniform_real(RealType l, RealType r) {
        static_assert(std::is_floating_point<RealType>::value,
                      "template argument must be an floating point type");
        assert(l <= r);
        return std::uniform_real_distribution<RealType>{l, r}(rnd);
    }
    bool uniform_bool() { return uniform<int>(0, 1) == 1; }
    template<class T = ll> std::pair<T, T> uniform_pair(T l, T r) {
        assert(l < r);
        T a, b;
        do {
            a = uniform<T>(l, r);
            b = uniform<T>(l, r);
        } while (a == b);
        if (a > b) swap(a, b);
        return {a, b};
    }
    template<class T = ll> std::vector<T> choice(int n, T l, T r) {
        assert(l <= r);
        assert(T(n) <= (r - l + 1));
        std::set<T> res;
        while ((int)res.size() < n) res.insert(uniform<T>(l, r));
        return {res.begin(), res.end()};
    }
    template<class Iter> void shuffle(const Iter& first, const Iter& last) {
        std::shuffle(first, last, rnd);
    }
    template<class T> std::vector<T> permutation(T n) {
        std::vector<T> res(n);
        rep (i, n) res[i] = i;
        shuffle(all(res));
        return res;
    }
    template<class T = ll>
    std::vector<T> choice_shuffle(int n, T l, T r, bool sorted = true) {
        assert(l <= r);
        assert(T(n) <= (r - l + 1));
        std::vector<T> res(r - l + 1);
        rep (i, l, r + 1) res[i - l] = i;
        shuffle(all(res));
        res.erase(res.begin() + n, res.end());
        if (sorted) sort(all(res));
        return res;
    }
};

using Random32 = Random<std::mt19937>;
Random32 rand32;
using Random64 = Random<std::mt19937_64>;
Random64 rand64;

/**
 * @brief Random
 * @docs docs/random/Random.md
 */
