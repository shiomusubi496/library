#pragma once

#include "../other/template.hpp"
#include "ZAlgorithm.hpp"

// template<class Cont>
using Cont = std::string;
std::vector<std::tuple<int, int, int>> run_enumerate(const Cont& s) {
    int n = s.size();
    auto calc = [&](Cont s, Cont t) {
        int n = s.size(), m = t.size();
        Cont c = t;
        c.resize(n + m * 2);
        rep (i, n) c[i + m] = s[i];
        rep (i, m) c[i + n + m] = t[i];
        std::reverse(all(s));
        auto z1 = z_algorithm(s), z2 = z_algorithm(c);
        std::vector<std::tuple<int, int, int>> res;
        reps (p, n) {
            ll a = p;
            if (p < n) a += z1[p];
            ll b = std::min(z2[n + m - p], m);
            if (a + b >= 2 * p) res.emplace_back(p, a, b);
        }
        return res;
    };
    std::vector<std::vector<std::pair<int, int>>> res(n + 1);
    rec_lambda([&](auto&& self, int l, int r) -> void {
        if (l + 1 == r) return;
        int m = (l + r) / 2;
        self(l, m); self(m, r);
        Cont cl(s.begin() + l, s.begin() + m), cr(s.begin() + m, s.begin() + r);
        for (auto [p, a, b] : calc(cl, cr)) res[p].emplace_back(m - a, m + b);
        std::reverse(all(cl));
        std::reverse(all(cr));
        for (auto [p, a, b] : calc(cr, cl)) res[p].emplace_back(m - b, m + a);
    })(0, s.size());
    std::vector<std::tuple<int, int, int>> tmp, ans;
    reps (p, n) {
        std::sort(all(res[p]), [&](const auto& a, const auto& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        int t = -1;
        for (auto [l, r] : res[p]) {
            if (t >= r) continue;
            t = r;
            tmp.emplace_back(l, r, p);
        }
    }
    std::sort(all(tmp));
    for (auto [l, r, p] : tmp) {
        if (ans.empty() || std::get<1>(ans.back()) != l || std::get<2>(ans.back()) != r) {
            ans.emplace_back(p, l, r);
        }
    }
    std::sort(all(ans));
    return ans;
}
