#pragma once

#include "../other/template.hpp"

template<char MIN_CHAR = 'A', char MAX_CHAR = 'z'>
class AhoCorasick {
private:
    static constexpr char ALPH = MAX_CHAR - MIN_CHAR + 1;
    std::vector<std::array<int, ALPH>> nxt;
    std::vector<int> par, fail;
    int add_node() {
        nxt.push_back({});
        nxt.back().fill(0);
        par.push_back(0);
        fail.push_back(0);
        return par.size() - 1;
    }

public:
    AhoCorasick() { add_node(); }
    void insert(const std::string& s) {
        int cur = 0;
        for (char c : s) {
            if (nxt[cur][c - MIN_CHAR] == 0) {
                nxt[cur][c - MIN_CHAR] = add_node();
                par.back() = cur;
            }
            cur = nxt[cur][c - MIN_CHAR];
        }
    }
    void build() {
        std::queue<int> que;
        rep (i, ALPH) if (nxt[0][i] != 0) que.push(nxt[0][i]);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            rep (i, ALPH) {
                int& u = nxt[v][i];
                if (u != 0) {
                    fail[u] = nxt[fail[v]][i];
                    que.push(u);
                }
                else {
                    u = nxt[fail[v]][i];
                }
            }
        }
    }
    int get_node(const std::string& s) const {
        int cur = 0;
        for (char c : s) cur = nxt[cur][c - MIN_CHAR];
        return cur;
    }
    int size() const { return par.size(); }
    int get_par(int i) const { return par[i]; }
    int get_fail(int i) const { return fail[i]; }
};
