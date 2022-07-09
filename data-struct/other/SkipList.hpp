#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../../random/Random.hpp"

using M = Monoid::Max<ll>;
using Rand = Random32;

class SkipList {
  protected:
    using T = typename M::value_type;
    static inline int get_level(Rand& rnd) {
        int level = 1;
        while (rnd() & 1) ++level;
        return level;
    }
    struct node;
    using node_ptr = node*;
    struct next_node {
        node_ptr node;
        int dist;
        T sm;
    };
    struct node {
        std::vector<next_node> nxt, prv;
        int level() const {
            assert(nxt.size() == prv.size());
            return nxt.size();
        }
        node(Rand& rnd) : node(get_level(rnd)) {}
        node(int lev) : nxt(lev, {nullptr, 0, M::id()}), prv(lev, {nullptr, 0, M::id()}) {}
    };
    using nodepair = std::pair<node_ptr, node_ptr>;
    Rand rnd;
    nodepair sl;
    static inline void calc(const node_ptr& l, int k) {
        l->nxt[k].sm = l->nxt[k - 1].sm;
        for (node_ptr ptr = l->nxt[k - 1].node; ptr != l->nxt[k].node; ptr = ptr->nxt[k - 1].node) {
            l->nxt[k].sm = M::op(l->nxt[k].sm, ptr->nxt[k - 1].sm);
        }
        l->nxt[k].node->prv[k].sm = l->nxt[k].sm;
    }
    static void match_level(nodepair& lhs, nodepair& rhs) {
        const int llv = lhs.first->level(), rlv = rhs.second->level();
        if (llv < rlv) {
            lhs.first->prv.resize(rlv, next_node(lhs.first->prv.back()));
            lhs.first->nxt.resize(rlv, next_node(lhs.first->nxt.back()));
            lhs.second->prv.resize(rlv, next_node(lhs.second->prv.back()));
            lhs.second->nxt.resize(rlv, next_node(lhs.second->nxt.back()));
        }
        else if (llv > rlv) {
            rhs.first->prv.resize(llv, next_node(rhs.first->prv.back()));
            rhs.first->nxt.resize(llv, next_node(rhs.first->nxt.back()));
            rhs.second->prv.resize(llv, next_node(rhs.second->prv.back()));
            rhs.second->nxt.resize(llv, next_node(rhs.second->nxt.back()));
        }
    }
    static nodepair merge(nodepair&& lhs, nodepair&& rhs, Rand& rnd) {
        assert(lhs.first != rhs.first);
        assert(lhs.second != rhs.second);
        if (lhs.first == lhs.second) {
            delete lhs.first;
            return std::move(rhs);
        }
        if (rhs.first == rhs.second) {
            delete rhs.first;
            return std::move(lhs);
        }
        match_level(lhs, rhs);
        rep (i, lhs.first->level()) {
            auto&& l = lhs.second->prv[i];
            auto&& r = rhs.first;
            l.node->nxt[i].node = r;
            r->prv[i] = std::move(l);
        }
        delete lhs.second;
        const int lev = get_level(rnd);
        while (lev < rhs.first->level()) {
            const int h = rhs.first->level();
            const auto& l = std::move(rhs.first->prv.back()); rhs.first->prv.pop_back();
            const auto& r = std::move(rhs.first->nxt.back()); rhs.first->nxt.pop_back();
            T sm = M::op(l.sm, r.sm);
            l.node->nxt[h - 1] = {r.node, l.dist + r.dist, sm};
            r.node->prv[h - 1] = {l.node, l.dist + r.dist, std::move(sm)};
        }
        if (lev >= rhs.first->level()) {
            lhs.first->prv.resize(lev + 1, next_node(lhs.first->prv.back()));
            lhs.first->nxt.resize(lev, next_node(lhs.first->nxt.back()));
            rhs.first->prv.resize(lev, next_node(rhs.first->prv.back()));
            rhs.first->nxt.resize(lev, next_node(rhs.first->nxt.back()));
            rhs.second->prv.resize(lev, next_node(rhs.second->prv.back()));
            rhs.second->nxt.resize(lev + 1, next_node(rhs.second->nxt.back()));
            const auto& l = rhs.first->prv.back();
            const auto& r = rhs.first->nxt.back();
            T sm = M::op(l.sm, r.sm);
            lhs.first->nxt.emplace_back(rhs.second, l.dist + r.dist, sm);
            rhs.second->prv.emplace_back(lhs.first, l.dist + r.dist, std::move(sm));
        }
        return {lhs.first, rhs.second};
    }
    static std::pair<nodepair, nodepair> split(nodepair&& sl, int k) {
        const int n = sl.first->nxt.back().dist;
        assert(0 <= k && k <= n);
        if (n == 0) {
            node_ptr np = new node(sl.first->level());
            return {std::move(sl), {np, np}};
        }
        if (k == 0) {
            node_ptr np = new node(sl.first->level());
            return {{np, np}, std::move(sl)};
        }
        if (k == n) {
            node_ptr np = new node(sl.first->level());
            return {std::move(sl), {np, np}};
        }
        const int h = sl.first->level();
        std::vector<node_ptr> lft(h);
        std::vector<int> idx(h);
        lft[h - 1] = sl.first;
        idx[h - 1] = 0;
        rrep (i, h - 1) {
            lft[i] = lft[i + 1];
            idx[i] = idx[i + 1];
            while (idx[i] + lft[i]->nxt[i].dist < k) {
                idx[i] += lft[i]->nxt[i].dist;
                lft[i] = lft[i]->nxt[i].node;
            }
        }
        node_ptr npl = new node(h);
        node_ptr npr = lft[0]->nxt[0].node;
        rep (i, h) {
            const auto& l = lft[i];
            const auto& r = lft[i]->nxt[i].node;
            const int d = l->nxt[i].dist;
            l->nxt[i] = {npl, k - idx[i], l->nxt[i].sm};
            npl->prv[i] = {l, k - idx[i], l->nxt[i].sm};
            if (i != 0) calc(l, i);
            if (npr == r) {
                r->prv[i] = {nullptr, 0, M::id()};
            }
            else {
                npr->nxt.emplace_back(r, d + idx[i] - k, M::id());
                r->prv[i] = {npr, d + idx[i] - k, M::id()};
                calc(npr, i);
            }
        }
        return {{sl.first, npl}, {npr, sl.second}};
    }
    SkipList(const nodepair& sl, const Rand& rnd) : sl(sl), rnd(rnd) {}
  public:
    SkipList() : SkipList(Rand()) {}
    SkipList(const Rand &rnd) : rnd(rnd) {
        sl.first = sl.second = new node(1);
    }
    SkipList(const SkipList&) = delete;
    SkipList(SkipList&&) = default;
    SkipList& operator=(const SkipList&) = delete;
    SkipList& operator=(SkipList&&) = default;
    int size() const { return sl.first->nxt[0].dist; }
    bool empty() const { return size() == 0; }
    friend SkipList merge(SkipList lhs, SkipList rhs) {
        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};
    }
    friend SkipList merge(SkipList&& lhs, SkipList&& rhs) {
        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};
    }
    friend SkipList merge(SkipList lhs, SkipList&& rhs) {
        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};
    }
    friend SkipList merge(SkipList&& lhs, SkipList rhs) {
        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};
    }
};

/**
 * @brief SkipList
 * @docs docs/SkipList.md
 */
