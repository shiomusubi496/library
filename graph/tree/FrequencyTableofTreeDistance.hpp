#pragma once

#include "../../other/template.hpp"
#include "../../math/ChineseRemainder.hpp"
#include "../../math/ModInt.hpp"
#include "../../math/convolution/Convolution.hpp"
#include "../Graph.hpp"
#include "TreeCentroid.hpp"

template<class T> class FrequencyTableofTreeDistance {
private:
    static constexpr int MOD1 = 469762049;
    static constexpr int MOD2 = 1811939329;
    using mint1 = static_modint<MOD1>;
    using mint2 = static_modint<MOD2>;

    int n;
    const Graph<T>& G;
    CentroidDecomposition<T> C;
    std::vector<mint1> ans1;
    std::vector<mint2> ans2;
    std::vector<ll> ans;

    template<class M> void build(std::vector<M>& ans) {
        std::vector<int> st = {C.get_root()};
        st.reserve(n);
        std::vector<bool> seen(n, false);
        std::vector<std::tuple<int, int, int>> st2;
        st2.reserve(n);
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            seen[v] = true;
            std::vector<std::vector<M>> dist;
            dist.reserve(G[v].size());
            for (const auto& s : G[v]) {
                if (seen[s.to]) continue;
                dist.push_back(std::vector<M>(2, 0));
                st2.emplace_back(s.to, -1, 1);
                while (!st2.empty()) {
                    int u, p, d;
                    std::tie(u, p, d) = st2.back();
                    st2.pop_back();
                    if ((int)dist.back().size() == d) dist.back().push_back(1);
                    else ++dist.back()[d];
                    for (const auto& e : G[u]) {
                        if (e.to == p || seen[e.to]) continue;
                        st2.emplace_back(e.to, u, d + 1);
                    }
                }
            }
            sort(all(dist),
                 [](const std::vector<M>& a, const std::vector<M>& b) {
                     return a.size() < b.size();
                 });
            std::vector<M> tmp;
            for (const auto& d : dist) {
                if (tmp.empty()) {
                    tmp = d;
                    continue;
                }
                auto tmp2 = convolution(tmp, d);
                rep (i, tmp2.size()) ans[i] += tmp2[i];
                tmp.resize(d.size());
                rep (i, d.size()) tmp[i] += d[i];
            }
            rep (i, tmp.size()) ans[i] += tmp[i];
            for (const auto& e : C.get()[v]) st.push_back(e.to);
        }
    }

public:
    FrequencyTableofTreeDistance(const Graph<T>& G_)
        : n(G_.size()), G(G_), C(G_), ans1(n, 0), ans2(n, 0) {
        build(ans1);
        build(ans2);
        ans.resize(n);
        ans[0] = n;
        rep (i, 1, n) {
            ans[i] = ChineseRemainder(ans1[i].get(), MOD1, ans2[i].get(), MOD2)
                         .first;
        }
    }
    const std::vector<ll>& get() const& { return ans; }
    std::vector<ll> get() && { return std::move(ans); }
};

/**
 * @brief Frequency Table of Tree Distance
 * @docs docs/graph/tree/FrequencyTableofTreeDistance.md
 */
