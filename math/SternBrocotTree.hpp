#pragma once

#include "../other/template.hpp"
#include "Rational.hpp"

template<class T> class SternBrocotTree {
public:
    using Rat = Rational<T, true>;

    static std::vector<std::pair<char, int>> encode_path(Rat x) {
        std::vector<std::pair<char, int>> res;
        T a = x.get_num(), b = x.get_den();
        while (a != 1 || b != 1) {
            if (a > b) {
                T tmp = (a - 1) / b;
                res.emplace_back('R', tmp);
                a -= tmp * b;
            }
            else {
                T tmp = (b - 1) / a;
                res.emplace_back('L', tmp);
                b -= tmp * a;
            }
        }
        return res;
    }
    static Rat decode_path(std::vector<std::pair<char, int>> path, Rat s = 1) {
        std::reverse(all(path));
        T a = s.get_num(), b = s.get_den();
        for (const auto& p : path) {
            if (p.first == 'R') a += b * p.second;
            else b += a * p.second;
        }
        return Rat(a, b);
    }
    static Rat lca(Rat x, Rat y) {
        auto px = encode_path(x), py = encode_path(y);
        std::vector<std::pair<char, int>> res;
        rep (i, std::min(px.size(), py.size())) {
            const auto &a = px[i], b = py[i];
            if (a.first != b.first) break;
            res.emplace_back(a.first, std::min(a.second, b.second));
            if (a.second != b.second) break;
        }
        return decode_path(res);
    }
    static Rat ancestor(Rat x, T k) {
        if (k == 0) return 1;
        auto px = encode_path(x);
        rep (i, px.size()) {
            const auto& a = px[i];
            if (a.second >= k) {
                px[i].second = k;
                px.erase(px.begin() + i + 1, px.end());
                return decode_path(px);
            }
            k -= a.second;
        }
        return -1;
    }
    static std::pair<Rat, Rat> range(Rat x) {
        auto px = encode_path(x);
        return {decode_path(px, {0, 1}), decode_path(px, {1, 0})};
    }
    template<class Cond> static std::pair<Rat, Rat> max_right(Cond cond, T n) {
        assert(n >= 1);
        auto f = [&](Rat a, Rat b, T x) {
            return Rat{a.get_num() + x * b.get_num(),
                       a.get_den() + x * b.get_den()};
        };
        Rat l = {0, 1}, r = {1, 0}, m = {1, 1};
        if (!cond(l)) return {-1, l};
        bool flag = cond(m);
        while (true) {
            if (flag) {
                T ok = 0, ng = 1;
                while (true) {
                    auto tmp = f(m, r, ng);
                    if (std::max(tmp.get_num(), tmp.get_den()) > n ||
                        !cond(tmp))
                        break;
                    ok = ng;
                    ng <<= 1;
                }
                while (ng - ok > 1) {
                    T mid = (ok + ng) >> 1;
                    auto tmp = f(m, r, mid);
                    if (std::max(tmp.get_num(), tmp.get_den()) > n ||
                        !cond(tmp))
                        ng = mid;
                    else ok = mid;
                }
                l = f(m, r, ok);
                m = f(m, r, ng);
                if (std::max(m.get_num(), m.get_den()) > n) return {l, r};
            }
            else {
                T ok = 0, ng = 1;
                while (true) {
                    auto tmp = f(m, l, ng);
                    if (std::max(tmp.get_num(), tmp.get_den()) > n || cond(tmp))
                        break;
                    ok = ng;
                    ng <<= 1;
                }
                while (ng - ok > 1) {
                    T mid = (ok + ng) >> 1;
                    auto tmp = f(m, l, mid);
                    if (std::max(tmp.get_num(), tmp.get_den()) > n || cond(tmp))
                        ng = mid;
                    else ok = mid;
                }
                r = f(m, l, ok);
                m = f(m, l, ng);
                if (std::max(m.get_num(), m.get_den()) > n) return {l, r};
            }
            flag = !flag;
        }
        return {-1, -1};
    }
};

/**
 * @brief Stern-Brocot Tree
 * @docs docs/math/SternBrocotTree.md
 */
