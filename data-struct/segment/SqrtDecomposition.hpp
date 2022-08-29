#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class T, class F, class G = void, class A = void>
class SqrtDecomposition;

template<class T, class F> class SqrtDecomposition<T, F, void, void> {
    static_assert(std::is_same<typename function_traits<F>::argument_tuple,
                               std::tuple<std::vector<T>&&>>::value,
                  "F must take a single argument of type vector<T>&&");

protected:
    using U = typename function_traits<F>::result_type;
    int n, b, nb;
    F f;
    std::vector<T> v;
    std::vector<U> data;
    virtual void eval(int) { return; }

public:
    SqrtDecomposition(const std::vector<T>& v_, const F& f) : f(f) { init(v_); }
    SqrtDecomposition(const std::vector<T>& v_, int b_, const F& f) : f(f) {
        init(v_, b_);
    }
    void init(const std::vector<T>& v_, int b_ = -1) {
        v = v_;
        n = v.size();
        if (b_ == -1) b_ = sqrt(n);
        b = b_;
        nb = n / b;
        data.reserve(nb);
        rep (i, nb) {
            std::vector<T> v2(v.begin() + i * b, v.begin() + (i + 1) * b);
            data.push_back(f(std::move(v2)));
        }
    }
    template<class M, class G, class H>
    auto prod(int l, int r, const G& g, const H& h) -> typename std::enable_if<
        Monoid::is_monoid<M>::value &&
            std::is_same<decltype(g(std::declval<T>())),
                         typename M::value_type>::value &&
            std::is_same<decltype(h(std::declval<U>())),
                         typename M::value_type>::value,
        typename M::value_type>::type {
        using S = typename M::value_type;
        assert(0 <= l && l <= r && r <= n);
        const int lb = l / b, rb = r / b;
        if (lb == rb) {
            if (lb < nb) eval(lb);
            S res = M::id();
            rep (i, l, r) res = M::op(res, g(v[i]));
            return res;
        }
        eval(lb);
        if (rb < nb) eval(rb);
        S res = M::id();
        rep (i, l, b * (lb + 1)) res = M::op(res, g(v[i]));
        rep (i, lb + 1, rb) res = M::op(res, h(data[i]));
        rep (i, rb * b, r) res = M::op(res, g(v[i]));
        return res;
    }
    template<class G>
    auto update(int k, const G& g) -> typename std::enable_if<
        std::is_same<decltype(g(std::declval<T&>())), void>::value>::type {
        assert(0 <= k && k < n);
        const int bk = k / b;
        if (bk < nb) eval(bk);
        g(v[k]);
        if (bk < nb) {
            std::vector<T> v2(v.begin() + bk * b, v.begin() + (bk + 1) * b);
            data[bk] = f(std::move(v2));
        }
    }
    void set(int k, const T& x) {
        update(k, [&](T& y) -> void { y = x; });
    }
};

template<class T, class F, class G, class A>
class SqrtDecomposition : public SqrtDecomposition<T, F, void> {
private:
    using Base = SqrtDecomposition<T, F, void>;
    using E = typename A::E;
    using U = typename Base::U;
    using S = typename E::value_type;

    static_assert(std::is_same<typename A::M::value_type, T>::value,
                  "A::M::value_type and T must be same");

    G g;
    std::vector<S> lazy;
    std::vector<bool> lazyflag;
    void eval(int i) override {
        if (lazyflag[i]) {
            rep (j, this->b)
                this->v[i * this->b + j] =
                    A::op(lazy[i], this->v[i * this->b + j]);
            lazyflag[i] = false;
        }
    }
    void all_apply(const S& x, int i) {
        g(x, this->data[i]);
        if (lazyflag[i]) {
            lazy[i] = E::op(lazy[i], x);
        }
        else {
            lazy[i] = x;
            lazyflag[i] = true;
        }
    }

public:
    SqrtDecomposition(const std::vector<T>& v_, const F& f, const G& g)
        : Base(v_, f), g(g), lazy(this->nb), lazyflag(this->nb, false) {}
    SqrtDecomposition(const std::vector<T>& v_, int b_, const F& f, const G& g)
        : Base(v_, b_, f), g(g), lazy(this->nb), lazyflag(this->nb, false) {}
    void apply(int k, const S& x) {
        this->update(k, [&](T& y) -> void { y = A::op(x, y); });
    }
    auto apply(int l, int r, const S& x) -> typename std::enable_if<
        std::is_same<decltype(g(x, std::declval<U&>())), void>::value>::type {
        assert(0 <= l && l <= r && r <= this->n);
        const int lb = l / this->b, rb = r / this->b;
        if (lb == rb) {
            if (lb < this->nb) eval(lb);
            rep (i, l, r) this->v[i] = A::op(x, this->v[i]);
            if (lb < this->nb) {
                std::vector<T> v2(this->v.begin() + lb * this->b,
                                  this->v.begin() + (lb + 1) * this->b);
                this->data[lb] = this->f(std::move(v2));
            }
            return;
        }
        eval(lb);
        if (rb < this->nb) eval(rb);
        rep (i, l, this->b * (lb + 1)) this->v[i] = A::op(x, this->v[i]);
        rep (i, lb + 1, rb) all_apply(x, i);
        rep (i, rb * this->b, r) this->v[i] = A::op(x, this->v[i]);
        {
            std::vector<T> v2(this->v.begin() + lb * this->b,
                              this->v.begin() + (lb + 1) * this->b);
            this->data[lb] = this->f(std::move(v2));
        }
        if (rb < this->nb) {
            std::vector<T> v2(this->v.begin() + rb * this->b,
                              this->v.begin() + (rb + 1) * this->b);
            this->data[rb] = this->f(std::move(v2));
        }
    }
};

/**
 * @brief SqrtDecomposition(平方分割)
 * @docs docs/data-struct/segment/SqrtDecomposition.md
 */
