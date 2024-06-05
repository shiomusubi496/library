#pragma once

#include "../../other/template.hpp"
#include "../Graph.hpp"

template<class T> class ComplementConnectedComponents {
private:
    int n, sz;
    const Graph<T>& G;
    std::vector<int> cmp;
    void init() {
        n = G.size();
        cmp.assign(n, -1);
        std::vector<int> rem, st;
        rem.resize(n);
        std::iota(all(rem), 0);
        st.reserve(n);
        std::vector<bool> flg(n, false);
        sz = 0;
        while (!rem.empty()) {
            int v = rem.back();
            rem.pop_back();
            cmp[v] = sz++;
            st.push_back(v);
            while (!st.empty()) {
                int v = st.back();
                st.pop_back();
                for (const auto& e : G[v]) flg[e.to] = true;
                std::vector<int> nxt;
                for (int u : rem) {
                    if (flg[u]) {
                        nxt.push_back(u);
                    }
                    else {
                        cmp[u] = cmp[v];
                        st.push_back(u);
                    }
                }
                rem = std::move(nxt);
                for (const auto& e : G[v]) flg[e.to] = false;
            }
        }
    }

public:
    ComplementConnectedComponents(const Graph<T>& G) : G(G) { init(); }
    int size() const { return sz; }
    int operator[](int k) const { return cmp[k]; }
    std::vector<std::vector<int>> groups() const {
        std::vector<std::vector<int>> res(sz);
        rep (i, n) res[cmp[i]].push_back(i);
        return res;
    }
};
