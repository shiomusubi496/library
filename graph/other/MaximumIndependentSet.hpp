#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<unsigned int SZ = 64>
class MinimumVertexCover {
private:
    int n;
    std::vector<std::bitset<SZ>> G;
    std::bitset<SZ> ans;
    std::vector<int> res;
    void dfs(std::bitset<SZ> used, std::bitset<SZ> flag) {
        if (used.count() >= ans.count()) return;
        int v = -1, deg = -1;
        rep (i, n) if (flag[i]) {
            auto tmp = flag & G[i];
            int d = tmp.count();
            if (d <= 1) {
                flag.reset(i);
                dfs(used | tmp, flag ^ tmp);
                return;
            }
            if (d > deg) {
                deg = d;
                v = i;
            }
        }
        if (v == -1) {
            ans = used;
            return;
        }
        auto tmp = flag & G[v];
        {
            used.set(v);
            flag.reset(v);
            dfs(used, flag);
            used.reset(v);
            flag.set(v);
        }
        {
            flag.reset(v);
            dfs(used | tmp, flag ^ tmp);
            flag.set(v);
        }
    }

public:
    template<class T>
    MinimumVertexCover(const Graph<T>& G_) {
        n = G_.size();
        G.assign(n, std::bitset<SZ>());
        rep (i, n) {
            each_const (e : G_[i]) G[i].set(e.to);
        }
        ans.set();
        dfs(std::bitset<SZ>(), std::bitset<SZ>().set());
        rep (i, n) {
            if (ans[i]) res.push_back(i);
        }
    }
    int size() const { return res.size(); }
    const std::vector<int>& get() const& { return res; }
    std::vector<int> get() && { return std::move(res); }
    const std::bitset<SZ>& get_bitset() const& { return ans; }
    std::bitset<SZ> get_bitset() && { return std::move(ans); }
};

template<unsigned int SZ = 64>
class MaximumIndependentSet {
private:
    std::vector<int> res;

public:
    template<class T>
    MaximumIndependentSet(const Graph<T>& G) {
        int n = G.size();
        auto bit = MinimumVertexCover<SZ>(G).get_bitset();
        rep (i, n) {
            if (!bit[i]) res.push_back(i);
        }
    }
    int size() const { return res.size(); }
    const std::vector<int>& get() const& { return res; }
    std::vector<int> get() && { return std::move(res); }
};

/**
 * @brief MaximumIndependentSet(最大独立集合)
 * @docs docs/graph/other/MaximumIndependentSet.md
 */
