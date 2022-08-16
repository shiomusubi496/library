#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../../other/monoid.hpp"
#include "SparseTable.hpp"

template<class M> class LinearRMQ {
private:
    using T = typename M::value_type;
    int n, b, m;
    std::vector<T> v;
    std::vector<std::vector<int>> bt;
    SparseTable<M> st;
    std::vector<int> lsbtable;
    int prod_in_backet(int k, int l, int r) const {
        int a = bt[k][r] & ~((1 << l) - 1);
        if (a == 0) return r;
        return lsbtable[a];
    }
    T internal_prod(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        --r;
        int lb = l / b, rb = r / b;
        int lp = l - lb * b, rp = r - rb * b;
        if (lb == rb) return v[lb * b + prod_in_backet(lb, lp, rp)];
        if (lb + 1 == rb) {
            int x = lb * b + prod_in_backet(lb, lp, b - 1),
                y = rb * b + prod_in_backet(rb, 0, rp);
            return M::op(v[x], v[y]);
        }
        T res = st.prod(lb + 1, rb);
        {
            int a = lb * b + prod_in_backet(lb, lp, b - 1);
            res = M::op(v[a], res);
        }
        {
            int a = rb * b + prod_in_backet(rb, 0, rp);
            res = M::op(res, v[a]);
        }
        return res;
    }

public:
    LinearRMQ() = default;
    LinearRMQ(const std::vector<T>& v_) { init(v_); }
    void init(const std::vector<T>& v_) {
        v = v_;
        n = v.size();
        b = bitop::msb(n) / 2 + 1;
        m = (n + b - 1) / b;
        bt.assign(m, std::vector<int>(b, 0));
        std::vector<int> sta;
        sta.reserve(b);
        rep (i, m) {
            rep (j, b) {
                if (i * b + j >= n) break;
                while (!sta.empty() && M::op(v[i * b + sta.back()],
                                             v[i * b + j]) == v[i * b + j])
                    sta.pop_back();
                if (!sta.empty()) {
                    int t = sta.back();
                    bt[i][j] = bt[i][t] | (1 << t);
                }
                sta.push_back(j);
            }
            sta.clear();
        }
        std::vector<T> stv(m);
        rep (i, m) {
            stv[i] = v[i * b];
            rep (j, i * b + 1, (i + 1) * b) {
                if (j >= n) break;
                stv[i] = M::op(stv[i], v[j]);
            }
        }
        st.init(stv);
        lsbtable.resize(1 << b);
        rep (i, b) {
            rep (j, 1 << i, 1 << b, 1 << (i + 1)) lsbtable[j] = i;
        }
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<Monoid::has_id<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T prod(int l, int r) const {
        if (l == r) return M::id();
        return internal_prod(l, r);
    }
    template<bool AlwaysTrue = true,
             typename std::enable_if<!Monoid::has_id<M>::value &&
                                     AlwaysTrue>::type* = nullptr>
    T prod(int l, int r) const {
        return internal_prod(l, r);
    }
};

/**
 * @brief LinearRMQ(前計算$\Theta(N)$クエリ毎$\Theta(1)$のRMQ)
 * @docs docs/LinearRMQ.md
 */