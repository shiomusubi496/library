#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../../random/Random.hpp"

template<class A, class Rand = Random32, bool = Monoid::has_mul_op<A>::value>
class SkipList {
protected:
    using M = typename A::M;
    using E = typename A::E;
    using T = typename M::value_type;
    using U = typename E::value_type;
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
        U lazy;
        bool lazyflag;
        next_node(node_ptr n, int d, const T& s)
            : node(n), dist(d), sm(s), lazyflag(false) {}
        next_node(node_ptr n, int d, const T& s, const U& l)
            : node(n), dist(d), sm(s), lazy(l), lazyflag(true) {}
    };
    struct node {
        std::vector<next_node> nxt;
        std::vector<node_ptr> prv;
        int level() const {
            assert(nxt.size() == prv.size());
            return nxt.size();
        }
        node(Rand& rnd) : node(get_level(rnd)) {}
        node(int lev) : nxt(lev, {nullptr, 1, M::id()}), prv(lev, nullptr) {}
    };
    using nodepair = std::pair<node_ptr, node_ptr>;
    Rand rnd;
    nodepair sl;
    static inline void all_apply(const node_ptr& nd, int k, const U& x) {
        assert(0 <= k && k < nd->level());
        nd->nxt[k].sm = A::op(x, nd->nxt[k].sm);
        if (k != 0) {
            if (nd->nxt[k].lazyflag) {
                nd->nxt[k].lazy = E::op(nd->nxt[k].lazy, x);
            }
            else {
                nd->nxt[k].lazy = x;
                nd->nxt[k].lazyflag = true;
            }
        }
    }
    static inline void eval(const node_ptr& nd, int k) {
        assert(0 <= k && k < nd->level());
        if (k != 0 && nd->nxt[k].lazyflag) {
            for (auto ptr = nd; ptr != nd->nxt[k].node;
                 ptr = ptr->nxt[k - 1].node) {
                all_apply(ptr, k - 1, nd->nxt[k].lazy);
            }
            nd->nxt[k].lazyflag = false;
        }
    }
    static inline void all_eval(const nodepair& sl, int k) {
        auto nd = sl.first;
        int cnt = 0;
        rrep (i, sl.first->level(), 1) {
            while (cnt + nd->nxt[i].dist <= k) {
                cnt += nd->nxt[i].dist;
                nd = nd->nxt[i].node;
            }
            eval(nd, i);
        }
    }
    static inline void calc(const node_ptr& l, int k) {
        assert(1 <= k && k < l->level());
        l->nxt[k].sm = l->nxt[k - 1].sm;
        for (node_ptr ptr = l->nxt[k - 1].node; ptr != l->nxt[k].node;
             ptr = ptr->nxt[k - 1].node) {
            l->nxt[k].sm = M::op(l->nxt[k].sm, ptr->nxt[k - 1].sm);
        }
    }
    static inline void all_calc(const nodepair& sl, int k) {
        auto nd = sl.first;
        int cnt = 0;
        std::vector<node_ptr> nds(sl.first->level());
        rrep (i, sl.first->level(), 1) {
            while (cnt + nd->nxt[i].dist <= k) {
                cnt += nd->nxt[i].dist;
                nd = nd->nxt[i].node;
            }
            nds[i] = nd;
        }
        rep (i, 1, sl.first->level()) calc(nds[i], i);
    }
    static void match_level(nodepair& lhs, nodepair& rhs) {
        const int llv = lhs.first->level(), rlv = rhs.second->level();
        if (llv < rlv) {
            eval(lhs.first, llv - 1);
            lhs.first->prv.resize(rlv, {lhs.first->prv.back()});
            lhs.first->nxt.resize(rlv, {lhs.first->nxt.back()});
            lhs.second->prv.resize(rlv, {lhs.second->prv.back()});
            lhs.second->nxt.resize(rlv, {lhs.second->nxt.back()});
        }
        else if (llv > rlv) {
            eval(rhs.second, rlv - 1);
            rhs.first->prv.resize(llv, {rhs.first->prv.back()});
            rhs.first->nxt.resize(llv, {rhs.first->nxt.back()});
            rhs.second->prv.resize(llv, {rhs.second->prv.back()});
            rhs.second->nxt.resize(llv, {rhs.second->nxt.back()});
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
            l->nxt[i].node = r;
            r->prv[i] = std::move(l);
        }
        delete lhs.second;
        const int lev = get_level(rnd);
        while (lev < rhs.first->level()) {
            const int h = rhs.first->level();
            const auto lp = std::move(rhs.first->prv.back());
            const auto l = lp->nxt[h - 1];
            const auto r = std::move(rhs.first->nxt.back());
            eval(lp, h - 1);
            eval(rhs.first, h - 1);
            rhs.first->prv.pop_back();
            rhs.first->nxt.pop_back();
            lp->nxt[h - 1] = {r.node, l.dist + r.dist, M::op(l.sm, r.sm)};
            r.node->prv[h - 1] = lp;
        }
        if (lev >= lhs.first->level()) {
            eval(lhs.first, lhs.first->level() - 1);
            eval(rhs.first, lhs.first->level() - 1);
            lhs.first->prv.resize(lev + 1, {lhs.first->prv.back()});
            lhs.first->nxt.resize(lev, {lhs.first->nxt.back()});
            rhs.first->prv.resize(lev, {rhs.first->prv.back()});
            rhs.first->nxt.resize(lev, {rhs.first->nxt.back()});
            rhs.second->prv.resize(lev, {rhs.second->prv.back()});
            rhs.second->nxt.resize(lev + 1, {rhs.second->nxt.back()});
            const auto& lp = rhs.first->prv.back();
            const auto& l = lp->nxt[lev - 1];
            const auto& r = rhs.first->nxt.back();
            lhs.first->nxt.emplace_back(rhs.second, l.dist + r.dist,
                                        M::op(l.sm, r.sm));
            rhs.second->prv.push_back(lhs.first);
        }
        return {lhs.first, rhs.second};
    }
    static std::pair<nodepair, nodepair> split(nodepair&& sl, int k) {
        const int n = sl.first->nxt.back().dist;
        assert(0 <= k && k <= n);
        if (n == 0) {
            node_ptr np = new node(1);
            return {std::move(sl), {np, np}};
        }
        if (k == 0) {
            node_ptr np = new node(1);
            return {{np, np}, std::move(sl)};
        }
        if (k == n) {
            node_ptr np = new node(1);
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
        rrep (i, h, 1) eval(lft[i], i);
        node_ptr npl = new node(h);
        node_ptr npr = lft[0]->nxt[0].node;
        rep (i, h) {
            const auto l = lft[i];
            const auto r = lft[i]->nxt[i].node;
            const int d = l->nxt[i].dist;
            l->nxt[i] = {npl, k - idx[i], l->nxt[i].sm};
            npl->prv[i] = l;
            if (i != 0) calc(l, i);
            if (npr == r) {
                r->prv[i] = nullptr;
            }
            else {
                npr->prv.push_back(nullptr);
                npr->nxt.emplace_back(r, d + idx[i] - k, M::id());
                r->prv[i] = npr;
                calc(npr, i);
            }
        }
        return {{sl.first, npl}, {npr, sl.second}};
    }
    SkipList(const nodepair& sl, const Rand& rnd) : rnd(rnd), sl(sl) {}
    SkipList(nodepair&& sl, const Rand& rnd) : rnd(rnd), sl(std::move(sl)) {}
    static node_ptr get_ptr(const nodepair& sl, int k) {
        int cnt = 0;
        node_ptr nw = sl.first;
        rrep (i, sl.first->level()) {
            while (cnt + nw->nxt[i].dist <= k) {
                cnt += nw->nxt[i].dist;
                nw = nw->nxt[i].node;
            }
        }
        return nw;
    }

public:
    SkipList() : SkipList(Rand()) {}
    SkipList(const Rand& rnd) : rnd(rnd) { sl.first = sl.second = new node(1); }
    SkipList(const std::vector<T>& v, const Rand& rnd = Rand()) : rnd(rnd) {
        init(v);
    }
    SkipList(const SkipList& other) : SkipList(other.get_data(), other.rnd) {}
    SkipList(SkipList&&) = default;
    SkipList& operator=(const SkipList& other) {
        if (this == &other) return *this;
        return *this = SkipList(other);
    }
    SkipList& operator=(SkipList&&) = default;
    void init(const std::vector<T>& v) {
        const int n = v.size();
        std::vector<int> lev(n + 1);
        rep (i, 1, n) lev[i] = get_level(rnd);
        lev[0] = lev[n] = *max_element(lev.begin() + 1, lev.end() - 1) + 1;
        std::vector<node_ptr> nd(n + 1);
        rep (i, n + 1) nd[i] = new node(lev[i]);
        rep (i, n) {
            nd[i]->nxt[0] = {nd[i + 1], 1, v[i]};
            nd[i + 1]->prv[0] = nd[i];
        }
        nd[0]->prv[0] = nullptr;
        nd[n]->nxt[0] = {nullptr, 1, M::id()};
        rep (i, 1, lev[0]) {
            std::vector<int> idx;
            rep (j, n + 1) {
                if (lev[j] > i) idx.push_back(j);
            }
            const int m = idx.size();
            rep (j, m - 1) {
                nd[idx[j]]->nxt[i] = {nd[idx[j + 1]], idx[j + 1] - idx[j],
                                      nd[idx[j]]->nxt[i - 1].sm};
                for (node_ptr ptr = nd[idx[j]]->nxt[i - 1].node;
                     ptr != nd[idx[j + 1]]; ptr = ptr->nxt[i - 1].node) {
                    nd[idx[j]]->nxt[i].sm =
                        M::op(nd[idx[j]]->nxt[i].sm, ptr->nxt[i - 1].sm);
                }
                nd[idx[j + 1]]->prv[i] = nd[idx[j]];
            }
            nd[idx[0]]->prv[i] = nullptr;
            nd[idx[m - 1]]->nxt[i] = {nullptr, 1, M::id()};
        }
        sl = {nd[0], nd[n]};
    }
    int size() const { return sl.first->nxt.back().dist; }
    bool empty() const { return size() == 0; }
    void insert(int k, const T& sm) {
        assert(0 <= k && k <= size());
        auto s = split(std::move(sl), k);
        nodepair p{new node(1), new node(1)};
        p.first->nxt[0] = {p.second, 1, sm};
        p.second->prv[0] = p.first;
        sl = merge(merge(std::move(s.first), std::move(p), rnd),
                   std::move(s.second), rnd);
    }
    void erase(int k) {
        assert(0 <= k && k < size());
        auto s = split(std::move(sl), k);
        auto s2 = split(std::move(s.second), 1);
        sl = merge(std::move(s.first), std::move(s2.second), rnd);
    }
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= size());
        all_eval(sl, l);
        all_eval(sl, r - 1);
        auto np = get_ptr(sl, l);
        T sm = M::id();
        rrep (i, sl.first->level()) {
            while (1) {
                int t = std::min((int)i, np->level() - 1);
                if (l + np->nxt[t].dist > r) break;
                l += np->nxt[t].dist;
                sm = M::op(sm, np->nxt[t].sm);
                np = np->nxt[t].node;
            }
        }
        return sm;
    }
    T all_prod() const { return sl.first->nxt.back().sm; }
    T get(int k) const {
        assert(0 <= k && k < size());
        all_eval(sl, k);
        return get_ptr(sl, k)->nxt[0].sm;
    }
    void apply(int l, int r, const U& x) {
        assert(0 <= l && l <= r && r <= size());
        all_eval(sl, l);
        all_eval(sl, r - 1);
        auto np = get_ptr(sl, l);
        int idx = l;
        rrep (i, sl.first->level()) {
            while (1) {
                int t = std::min((int)i, np->level() - 1);
                if (idx + np->nxt[t].dist > r) break;
                idx += np->nxt[t].dist;
                all_apply(np, t, x);
                np = np->nxt[t].node;
            }
        }
        all_eval(sl, l);
        all_eval(sl, r - 1);
        all_calc(sl, l);
        all_calc(sl, r - 1);
    }
    template<class Upd> void update(int k, const Upd& upd) {
        assert(0 <= k && k < size());
        all_eval(sl, k);
        auto nd = get_ptr(sl, k);
        nd->nxt[0].sm = upd(nd->nxt[0].sm);
        all_calc(sl, k);
    }
    void set(int k, const T& x) {
        update(k, [&](const T&) { return x; });
    }
    void apply(int k, const U& x) {
        update(k, [&](const T& sm) { return E::op(x, sm); });
    }
    template<class C> int max_right(int l, const C& cond) const {
        assert(0 <= l && l <= size());
        assert(cond(M::id()));
        if (l == size()) return size();
        all_eval(sl, l);
        auto np = get_ptr(sl, l);
        T sm = M::id();
        rrep (i, sl.first->level()) {
            while (1) {
                int t = std::min((int)i, np->level() - 1);
                if (t != np->level() - 1) eval(np, t + 1);
                if (!cond(M::op(sm, np->nxt[t].sm))) break;
                sm = M::op(sm, np->nxt[t].sm);
                l += np->nxt[t].dist;
                np = np->nxt[t].node;
                if (np == sl.second) return size();
            }
        }
        return l;
    }
    template<class C> int min_left(int r, const C& cond) const {
        assert(0 <= r && r <= size());
        assert(cond(M::id()));
        if (r == 0) return 0;
        all_eval(sl, r - 1);
        auto np = get_ptr(sl, r);
        T sm = M::id();
        rrep (i, sl.first->level()) {
            while (1) {
                int t = std::min((int)i, np->level() - 1);
                if (t != np->level() - 1) eval(np->prv[t], t + 1);
                if (!cond(M::op(sm, np->prv[t]->nxt[t].sm))) break;
                sm = M::op(sm, np->prv[t]->nxt[t].sm);
                r -= np->prv[t]->nxt[t].dist;
                np = np->prv[t];
                if (np == sl.first) return 0;
            }
        }
        return r;
    }
    std::vector<T> get_data() const {
        rrep (i, sl.first->level(), 1) {
            for (node_ptr ptr = sl.first; ptr != sl.second;
                 ptr = ptr->nxt[i].node) {
                eval(ptr, i);
            }
        }
        std::vector<T> res;
        res.reserve(size());
        for (node_ptr ptr = sl.first; ptr != sl.second;
             ptr = ptr->nxt[0].node) {
            res.push_back(ptr->nxt[0].sm);
        }
        return res;
    }
    friend SkipList merge(SkipList lhs, SkipList rhs) {
        return {merge(std::move(lhs.sl), std::move(rhs.sl), lhs.rnd), lhs.rnd};
    }
    friend std::pair<SkipList, SkipList> split(SkipList sl, int k) {
        auto s = split(std::move(sl.sl), k);
        return {SkipList{std::move(s.first), sl.rnd},
                SkipList{std::move(s.second), sl.rnd}};
    }
};

template<class A, class Rand> class SkipList<A, Rand, true> {
protected:
    using Base = SkipList<Monoid::MultiAction<A>, Rand>;
    using T_ = typename A::M::value_type;
    using U_ = typename A::E::value_type;
    Base sl;
    using elm = typename Monoid::MultiAction<A>::M::value_type;
    static std::vector<elm> get_elm_vec(const std::vector<T_>& v) {
        const int n = v.size();
        std::vector<elm> res(n);
        rep (i, n) res[i] = {v[i], 1};
        return res;
    }
    SkipList(const Base& other) : sl(other) {}
    SkipList(Base&& other) : sl(std::move(other)) {}

public:
    SkipList() : SkipList(Rand()) {}
    SkipList(const Rand& rnd) : sl(rnd) {}
    SkipList(const std::vector<T_>& v, const Rand& rnd = Rand())
        : sl(get_elm_vec(v), rnd) {}
    void init(const std::vector<T_>& v) { sl.init(get_elm_vec(v)); }
    int size() const { return sl.size(); }
    bool empty() const { return sl.empty(); }
    void insert(int k, const T_& sm) { sl.insert(k, {sm, 1}); }
    void erase(int k) { sl.erase(k); }
    T_ prod(int l, int r) const { return sl.prod(l, r).val; }
    T_ all_prod() const { return sl.all_prod().val; }
    T_ get(int k) const { return sl.get(k).val; }
    void apply(int l, int r, const U_& x) { sl.apply(l, r, x); }
    template<class Upd> void update(int k, const Upd& upd) {
        sl.update(k, [&](const elm& e) -> elm { return {upd(e.val), e.len}; });
    }
    void set(int k, const T_& x) { sl.set(k, {x, 1}); }
    void apply(int k, const U_& x) { sl.apply(k, x); }
    template<class C> int max_right(int l, const C& cond) const {
        return sl.max_right(l,
                            [&](const elm& e) -> bool { return cond(e.val); });
    }
    template<class C> int min_left(int r, const C& cond) const {
        return sl.min_left(r,
                           [&](const elm& e) -> bool { return cond(e.val); });
    }
    std::vector<T_> get_data() const {
        std::vector<elm> d = sl.get_data();
        std::vector<T_> res(d.size());
        rep (i, d.size()) res[i] = d[i].val;
        return res;
    }
    friend SkipList merge(SkipList lhs, SkipList rhs) {
        return {merge(std::move(lhs.sl), std::move(rhs.sl))};
    }
    friend std::pair<SkipList, SkipList> split(SkipList sl, int k) {
        auto s = split(std::move(sl.sl), k);
        return {SkipList{std::move(s.first)}, SkipList{std::move(s.second)}};
    }
};

/**
 * @brief SkipList
 * @docs docs/SkipList.md
 */
