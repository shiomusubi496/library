#pragma once

#include "../../other/template.hpp"

template<class T>
class PartialPersistentArray {
private:
    int n;
    std::vector<std::vector<int>> tim;
    std::vector<std::vector<T>> val;
    int last_time;
public:
    PartialPersistentArray(const std::vector<T>& a) { init(a); }
    int now() const { return last_time; }
    void init(const std::vector<T>& a) {
        n = a.size();
        tim.resize(n);
        val.resize(n);
        for (int i = 0; i < n; i++) {
            tim[i].push_back(-1);
            val[i].push_back(a[i]);
        }
        last_time = 0;
    }
    void set(int k, const T& x) {
        assert(0 <= k && k < n);
        tim[k].push_back(last_time++);
        val[k].push_back(x);
    }
    T get(int k, int t) const {
        assert(0 <= k && k < n);
        assert(-1 <= t && t < now());
        int id = std::upper_bound(all(tim[k]), t) - tim[k].begin() - 1;
        return val[k][id];
    }
};

/**
 * @brief PartialPersistentArray(部分永続配列)
 * @docs docs/data-struct/other/PartialPersistentArray.md
 */
