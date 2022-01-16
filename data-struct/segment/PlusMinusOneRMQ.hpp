#pragma once

#include "../../other/template.hpp"
#include "../../other/bitop.hpp"
#include "../../other/monoid.hpp"
#include "SparseTable.hpp"

template<class T> class PlusMinusOneRMQ {
  protected:
    int n, b, m;
    std::vector<T> v;
    std::vector<int> ud;
    std::vector<std::vector<std::vector<int>>> lookup;
    struct PairMin {
        using value_type = std::pair<T, int>;
        static value_type op(const value_type& a, const value_type& b) {
            return a.first < b.first ? a : b;
        }
        static value_type id() {
            return {infinity<T>::value, -1};
        }
    };
    SparseTable<PairMin> st;
  public:
    PlusMinusOneRMQ() = default;
    PlusMinusOneRMQ(const std::vector<T>& v_) { init(v_); }
    void init(const std::vector<T>& v_) {
        v = v_;
        n = v.size();
        b = bitop::msb(n) / 2 + 1;
        m = (n + b - 1) / b;
        lookup = make_vec<int>(1 << (b - 1), b, b, -1);
        rep (i, 1 << (b - 1)) {
            T now = 0;
            rep (j, b) {
                T nw = now, mn = nw, id = j;
                lookup[i][j][j] = j;
                rep (k, j, b - 1) {
                    nw += ((i >> k) & 1) ? 1 : -1;
                    if (chmin(mn, nw)) lookup[i][j][k + 1] = id = k + 1;
                    else lookup[i][j][k + 1] = id;
                }
                now += ((i >> j) & 1) ? 1 : -1;
            }
        }
        ud.resize(m);
        rep (i, m) {
            rep (j, b - 1) {
                if (i * b + j + 1 >= n) break;
                if (v[i * b + j] + 1 == v[i * b + j + 1]) ud[i] |= (1 << j);
            }
        }
        std::vector<std::pair<T, int>> stv(m);
        rep (i, m) {
            stv[i] = {v[i * b], i * b};
            rep (j, 1, b) {
                if (i * b + j >= n) break;
                stv[i] = PairMin::op(stv[i], {v[i * b + j], i * b + j});
            }
        }
        st.init(stv);
    }
    int prod_idx(int l, int r) const {
        assert(0 <= l && l < r && r <= n);
        --r;
        int lb = l / b, rb = r / b;
        int lp = l - lb * b, rp = r - rb * b;
        if (lb == rb) return lb * b + lookup[ud[lb]][lp][rp];
        else if (lb + 1 == rb) {
            int x = lb * b + lookup[ud[lb]][lp][b - 1], y = rb * b + lookup[ud[rb]][0][rp];
            if (v[x] < v[y]) return x;
            else return y;
        }
        else {
            int res = st.prod(lb + 1, rb).second;
            {
                int a = lb * b + lookup[ud[lb]][lp][b - 1];
                if (v[a] < v[res]) res = a;
            }
            {
                int a = rb * b + lookup[ud[rb]][0][rp];
                if (v[a] < v[res]) res = a;
            }
            return res;
        }
        return -1;
    }
    T prod(int l, int r) const { return v[prod(l, r)]; }
};

/**
 * @brief PlusMinusOneRMQ($\pm1$RMQ)
 * @docs docs/PlusMinusOneRMQ.md
 */
