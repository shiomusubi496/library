#pragma once

#include "../../other/template.hpp"

class RangeSet {
  protected:
    int sz;
    std::set<std::pair<ll, ll>> st;
    typename std::set<std::pair<ll, ll>>::iterator
            st_emplace_hint(const typename std::set<std::pair<ll, ll>>::iterator& itr, ll l, ll r) {
        sz += r - l;
        return st.emplace_hint(itr, l, r);
    }
    typename std::set<std::pair<ll, ll>>::iterator
            st_erase(const typename std::set<std::pair<ll, ll>>::iterator& itr) {
        sz -= itr->second - itr->first;
        return st.erase(itr);
    }
  public:
    RangeSet() : sz(0) {}
    RangeSet(const std::set<std::pair<ll, ll>>& st_) : sz(0) {
        each_const (p : st_) insert(p.first, p.second);
    }
    bool empty() const { return st.empty(); }
    int size() const { return st.size(); }
    ll length() const { return sz; }
    const std::set<std::pair<ll, ll>>& get_data() const& { return st; }
    std::set<std::pair<ll, ll>>& get_data() & { return st; }
    std::set<std::pair<ll, ll>> get_data() && { return std::move(st); }
    auto insert(ll l, ll r) -> decltype(st.insert({l, r})) {
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
    auto insert(ll l) -> decltype(insert(l, l + 1)) { return insert(l, l + 1); }
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
};
