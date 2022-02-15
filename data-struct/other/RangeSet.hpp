#pragma once

#include "../../other/template.hpp"

class RangeSet {
  protected:
    using iterator = typename std::set<std::pair<ll, ll>>::iterator;
    int sz;
    std::set<std::pair<ll, ll>> st;
    iterator st_emplace_hint(const iterator& itr, ll l, ll r) {
        sz += r - l;
        return st.emplace_hint(itr, l, r);
    }
    iterator st_erase(const iterator& itr) {
        sz -= itr->second - itr->first;
        return st.erase(itr);
    }
  public:
    RangeSet() : sz(0) {}
    RangeSet(const std::set<std::pair<ll, ll>>& st_) : sz(0) {
        each_const (p : st_) insert(p.first, p.second);
    }
    iterator begin() const { return st.begin(); }
    iterator end() const { return st.end(); }
    bool empty() const { return st.empty(); }
    int size() const { return st.size(); }
    ll length() const { return sz; }
    const std::set<std::pair<ll, ll>>& get_data() const& { return st; }
    std::set<std::pair<ll, ll>>& get_data() & { return st; }
    std::set<std::pair<ll, ll>> get_data() && { return std::move(st); }
    std::pair<iterator, bool> insert(ll l, ll r) {
        assert(l <= r);
        if (l == r) return {st.end(), false};
        auto itr = st.lower_bound({l, r});
        if (itr != st.end() && itr->first == l) return {itr, false};
        if (itr != st.begin() && prev(itr)->first != l && r <= prev(itr)->second) {
            return {prev(itr), false};
        }
        sz += r - l; itr = st_emplace_hint(itr, l, r);
        while (itr != prev(st.end()) && next(itr)->first <= itr->second) {
            if (next(itr)->second <= itr->second) st_erase(next(itr));
            else {
                itr = st_emplace_hint(next(itr), itr->first, next(itr)->second);
                st_erase(prev(itr)); st_erase(next(itr));
            }
        }
        while (itr != st.begin() && itr->first <= prev(itr)->second) {
            if (itr->first == prev(itr)->first) st_erase(prev(itr));
            else {
                itr = st_emplace_hint(itr, prev(itr)->first, itr->second);
                st_erase(prev(itr)); st_erase(next(itr));
            }
        }
        return {itr, true};
    }
    std::pair<iterator, bool> insert(ll l) { return insert(l, l + 1); }
    void erase(ll l, ll r) {
        assert(l <= r);
        if (l == r) return;
        auto itr = st.lower_bound({l, r});
        while (itr != st.end() && itr->first < r) {
            if (itr->second <= r) itr = st_erase(itr);
            else {
                itr = st_emplace_hint(itr, r, itr->second);
                st_erase(prev(itr));
            }
        }
        if (itr != st.begin() && prev(itr)->first == l) st_erase(prev(itr));
        else if (itr != st.begin() && l < prev(itr)->second) {
            st_emplace_hint(prev(itr), prev(itr)->first, l);
            st_erase(prev(itr));
        }
    }
    void erase(ll l) { erase(l, l + 1); }
    bool include(ll k) {
        auto itr = st.lower_bound({k + 1, k + 1});
        return itr != st.begin() && k < prev(itr)->second;
    }
    std::pair<ll, ll> find(ll k) {
        auto itr = st.lower_bound({k + 1, k + 1});
        if (itr == st.begin()) return {-1, -1};
        --itr;
        if (itr->second <= k) return {-1, -1};
        return *itr;
    }
    friend RangeSet operator||(const RangeSet& lhs, const RangeSet& rhs) {
        RangeSet res = lhs;
        each_const (p : rhs.get_data()) res.insert(p.first, p.second);
        return res;
    }
    friend RangeSet operator&&(const RangeSet& lhs, const RangeSet& rhs) {
        RangeSet res;
        auto itr1 = lhs.begin(), itr2 = rhs.begin();
        while (itr1 != lhs.end() && itr2 != rhs.end()) {
            ll l = std::max(itr1->first, itr2->first);
            ll r = std::min(itr1->second, itr2->second);
            if (l < r) res.insert(l, r);
            if (itr1->second < itr2->second) ++itr1;
            else ++itr2;
        }
        return res;
    }
};

/**
 * @brief RangeSet(区間をstd::setで管理する例のやつ)
 * @docs docs/RangeSet.md
 */
