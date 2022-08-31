#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"

template<class A, bool = Monoid::has_mul_op<A>::value> class SegmentTreeBeats {
private:
    using M = typename A::M;
    using E = typename A::E;
    using T = typename M::value_type;
    using U = typename E::value_type;
    int h, n, ori;
    std::vector<T> data;
    std::vector<U> lazy;
    std::vector<bool> lazyflag;
    void all_apply(int k, const U& x) {
        data[k] = A::op(x, data[k]);
        if (k < n) {
            if (lazyflag[k]) {
                lazy[k] = E::op(lazy[k], x);
            }
            else {
                lazy[k] = x;
                lazyflag[k] = true;
            }
        }
    }
    void eval(int k) {
        if (lazyflag[k]) {
            all_apply(k << 1, lazy[k]);
            all_apply(k << 1 ^ 1, lazy[k]);
            lazyflag[k] = false;
        }
    }
    void calc(int k) { data[k] = M::op(data[k << 1], data[k << 1 ^ 1]); }

    template<class Upd>
    void update(int k, int a, int b, int p, const Upd& upd) {
        if (a + 1 == b) {
            data[k] = upd(data[k]);
            return;
        }
        eval(k);
        int m = (a + b) >> 1;
        if (p < m) update(k << 1, a, m, p, upd);
        else update(k << 1 ^ 1, m, b, p, upd);
        calc(k);
    }
    void apply(int k, int a, int b, int l, int r, const U& x) {
        if (r <= a || b <= l || A::break_cond(data[k], x)) return;
        if (l <= a && b <= r && A::tag_cond(data[k], x)) {
            all_apply(k, x);
            return;
        }
        eval(k);
        int m = (a + b) >> 1;
        apply(k << 1, a, m, l, r, x);
        apply(k << 1 ^ 1, m, b, l, r, x);
        calc(k);
    }
    T prod(int k, int a, int b, int l, int r) {
        if (r <= a || b <= l) return M::id();
        if (l <= a && b <= r) return data[k];
        eval(k);
        int m = (a + b) >> 1;
        return M::op(prod(k << 1, a, m, l, r), prod(k << 1 ^ 1, m, b, l, r));
    }

public:
    SegmentTreeBeats() : SegmentTreeBeats(0) {}
    SegmentTreeBeats(int n) : SegmentTreeBeats(std::vector<T>(n, M::id())) {}
    SegmentTreeBeats(int n, const T& v)
        : SegmentTreeBeats(std::vector<T>(n, v)) {}
    SegmentTreeBeats(const std::vector<T>& v) { init(v); }
    void init(const std::vector<T>& v) {
        ori = v.size();
        h = bitop::ceil_log2(ori);
        n = 1 << h;
        data.assign(n << 1, M::id());
        rep (i, ori) data[n + i] = v[i];
        rrep (i, n, 1) calc(i);
        lazy.resize(n);
        lazyflag.resize(n, false);
    }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < ori);
        update(1, 0, n, k, upd);
    }
    void set(int k, const T& x) {
        update(k, [&](const T&) -> T { return x; });
    }
    void apply(int k, const U& x) {
        update(k, [&](const T& a) -> T { return A::op(x, a); });
    }
    void apply(int l, int r, const U& x) {
        assert(0 <= l && l <= r && r <= ori);
        apply(1, 0, n, l, r, x);
    }
    T prod(int l, int r) {
        assert(0 <= l && l <= r && r <= ori);
        return prod(1, 0, n, l, r);
    }
    T all_prod() const { return data[1]; }
    T get(int k) { return prod(k, k + 1); }
};

template<class A> class SegmentTreeBeats<A, true> {
private:
    using T = typename A::M::value_type;
    using U = typename A::E::value_type;
    using elm = typename Monoid::LengthAction<A>::M::value_type;
    static std::vector<elm> get_elm_vec(const std::vector<T>& v) {
        const int n = v.size();
        std::vector<elm> res(n);
        rep (i, n) res[i] = elm{v[i], 1};
        return res;
    }
    SegmentTreeBeats<Monoid::LengthAction<A>> seg;

public:
    SegmentTreeBeats() : SegmentTreeBeats(0) {}
    SegmentTreeBeats(int n) : seg(n, {A::M::id(), 1}) {}
    SegmentTreeBeats(int n, const T& v) : seg(n, {v, 1}) {}
    SegmentTreeBeats(const std::vector<T>& v) : seg(get_elm_vec(v)) {}
    void init(const std::vector<T>& v) { init(get_elm_vec(v)); }
    T prod(int l, int r) { return seg.prod(l, r).val; }
    T get(int k) { return seg.get(k).val; }
    T all_prod() { return seg.all_prod().val; }
    template<class Upd> void update(int k, const Upd& upd) {
        seg.update(k, [&](const elm& a) -> elm { return {upd(a.val), a.len}; });
    }
    void set(int k, const T& x) { seg.set(k, {x, 1}); }
    void apply(int k, const U& x) { seg.apply(k, x); }
    void apply(int l, int r, const U& x) { seg.apply(l, r, x); }
};

namespace Monoid {

template<class T, T max_value = infinity<T>::max,
         T min_value = infinity<T>::min>
struct ChmaxChminAddAssignMaxMinSum {
    struct M {
        struct value_type {
            T mx, smx, cmx;
            T mn, smn, cmn;
            T sm;
        };
        static value_type id() {
            return {min_value, min_value, T{0}, max_value,
                    max_value, T{0},      T{0}};
        }
        static value_type get(T a) {
            value_type res = id();
            res.mx = res.mn = a;
            res.cmx = res.cmn = 1;
            res.sm = a;
            return res;
        }
        static value_type op(const value_type& a, const value_type& b) {
            value_type res;
            if (a.mx > b.mx) {
                res.mx = a.mx;
                res.smx = std::max(a.smx, b.mx);
                res.cmx = a.cmx;
            }
            else if (a.mx < b.mx) {
                res.mx = b.mx;
                res.smx = std::max(a.mx, b.smx);
                res.cmx = b.cmx;
            }
            else {
                res.mx = a.mx;
                res.smx = std::max(a.smx, b.smx);
                res.cmx = a.cmx + b.cmx;
            }
            if (a.mn < b.mn) {
                res.mn = a.mn;
                res.smn = std::min(a.smn, b.mn);
                res.cmn = a.cmn;
            }
            else if (a.mn > b.mn) {
                res.mn = b.mn;
                res.smn = std::min(a.mn, b.smn);
                res.cmn = b.cmn;
            }
            else {
                res.mn = a.mn;
                res.smn = std::min(a.smn, b.smn);
                res.cmn = a.cmn + b.cmn;
            }
            res.sm = a.sm + b.sm;
            return res;
        }
    };
    struct E {
        struct value_type {
            T mx, mn, ad;
            value_type() : mx(min_value), mn(max_value), ad(0) {}
            value_type(const T& chmx, const T& chmn, const T& ad)
                : mx(chmx), mn(chmn), ad(ad) {}
        };
        static value_type id() { return value_type{}; }
        static value_type op(const value_type& a, const value_type& b) {
            T bmx = b.mx == min_value ? min_value : b.mx - a.ad;
            T bmn = b.mn == max_value ? max_value : b.mn - a.ad;
            return {std::min(std::max(a.mx, bmx), bmn),
                    std::min(std::max(a.mn, bmx), bmn), a.ad + b.ad};
        }
    };
    using S = typename M::value_type;
    using U = typename E::value_type;
    static S mul_op(const U& a, int c, const S& b) {
        S res = b;
        if (a.mx > res.mn) {
            assert(a.mx < res.smn);
            res.sm += (a.mx - res.mn) * res.cmn;
            if (res.mn == res.mx) res.mn = res.mx = a.mx;
            else if (res.mn == res.smx) res.mn = res.smx = a.mx;
            else res.mn = a.mx;
        }
        if (a.mn < res.mx) {
            assert(a.mn > res.smx);
            res.sm += (a.mn - res.mx) * res.cmx;
            if (res.mx == res.mn) res.mx = res.mn = a.mn;
            else if (res.mx == res.smn) res.mx = res.smn = a.mn;
            else res.mx = a.mn;
        }
        if (res.mx != min_value) res.mx += a.ad;
        if (res.smx != min_value) res.smx += a.ad;
        if (res.mn != max_value) res.mn += a.ad;
        if (res.smn != max_value) res.smn += a.ad;
        res.sm += a.ad * c;
        return res;
    }
    static bool break_cond(const S& a, const U& b) {
        if (b.mx != min_value) return a.mn >= b.mx;
        if (b.mn != max_value) return a.mx <= b.mn;
        return false;
    }
    static bool tag_cond(const S& a, const U& b) {
        if (b.mx != min_value) return a.smn > b.mx;
        if (b.mn != max_value) return a.smx < b.mn;
        return true;
    }
};

} // namespace Monoid

/**
 * @brief SegmentTreeBeats!
 * @docs docs/data-struct/segment/SegmentTreeBeats.md
 */
