#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../../data-struct/segment/StarrySkyTree.hpp"
#include "../Graph.hpp"

class PermutationTree {
private:
    struct Node {
        int l, r;
        int mn, mx;
        int type; // 0 : prime, 1 : asc, -1 : desc
        int par;
        Node() : l(1 << 30), r(-1), mn(1 << 30), mx(-1), type(0), par(-1) {}
        Node(int l, int r, int m, int M, int t, int p)
            : l(l), r(r), mn(m), mx(M), type(t), par(p) {}
    };
    std::vector<Node> nodes;

    void add_child(int v, int p) {
        nodes[v].par = p;
        chmin(nodes[p].l, nodes[v].l);
        chmax(nodes[p].r, nodes[v].r);
        chmin(nodes[p].mn, nodes[v].mn);
        chmax(nodes[p].mx, nodes[v].mx);
    }

public:
    PermutationTree(const std::vector<int>& p) {
        int n = p.size();
        std::vector<int> st;
        st.reserve(2 * n);
        nodes.reserve(2 * n);
        nodes.resize(n);
        rep (i, n) nodes[i] = {(int)i, (int)i + 1, p[i], p[i] + 1, 0, -1};
        // RangeAddQueryRangeMinimumQuery<int> seg(n, 0);
        StarrySkyTree<Monoid::AddMin<int>> seg(n, 0);
        std::vector<int> mxs{-1}, mns{-1};
        mxs.reserve(n);
        mns.reserve(n);
        rep (i, n) {
            while (mxs.back() != -1 && p[mxs.back()] < p[i]) {
                seg.apply(mxs[mxs.size() - 2] + 1, mxs.back() + 1,
                          p[i] - p[mxs.back()]);
                mxs.pop_back();
            }
            while (mns.back() != -1 && p[mns.back()] > p[i]) {
                seg.apply(mns[mns.size() - 2] + 1, mns.back() + 1,
                          p[mns.back()] - p[i]);
                mns.pop_back();
            }
            mxs.push_back(i);
            mns.push_back(i);
            seg.apply(0, i, -1);
            int cur = i;
            while (!st.empty()) {
                int t = st.back();
                if ((nodes[t].type == 1 && nodes[t].mx == nodes[cur].mn) ||
                    (nodes[t].type == -1 && nodes[t].mn == nodes[cur].mx)) {
                    add_child(cur, t);
                    st.pop_back();
                    cur = t;
                }
                else if (nodes[t].mx == nodes[cur].mn ||
                         nodes[t].mn == nodes[cur].mx) {
                    int p = nodes.size();
                    nodes.emplace_back();
                    nodes[p].type = nodes[t].mx == nodes[cur].mn ? 1 : -1;
                    add_child(cur, p);
                    add_child(t, p);
                    st.pop_back();
                    cur = p;
                }
                else if (seg.prod(0, nodes[cur].l) == 0) {
                    int p = nodes.size();
                    nodes.emplace_back();
                    nodes[p].type = 0;
                    add_child(cur, p);
                    do {
                        add_child(st.back(), p);
                        st.pop_back();
                    } while (nodes[p].r - nodes[p].l !=
                             nodes[p].mx - nodes[p].mn);
                    cur = p;
                }
                else {
                    break;
                }
            }
            st.push_back(cur);
        }
        rep (i, n) nodes[i].type = 1;
    }

    int par(int v) const { return nodes[v].par; }
    int l(int v) const { return nodes[v].l; }
    int r(int v) const { return nodes[v].r; }
    int mn(int v) const { return nodes[v].mn; }
    int mx(int v) const { return nodes[v].mx; }
    int type(int v) const { return nodes[v].type; }
    bool is_linear(int v) const { return nodes[v].type != 0; }
    bool is_prime(int v) const { return nodes[v].type == 0; }
    int size() const { return nodes.size(); }
    UnweightedGraph tree() const {
        int n = nodes.size();
        UnweightedGraph g(n);
        rep (i, n)
            if (nodes[i].par != -1) {
                g.add_edge(nodes[i].par, i, true);
            }
        return g;
    }
    int root() const { return nodes.size() - 1; }
};

/**
 * @see https://codeforces.com/blog/entry/78898
 */
