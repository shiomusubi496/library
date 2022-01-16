#pragma once

#include "../../other/template.hpp"
#include "EulerTour.hpp"
#include "../../data-struct/segment/PlusMinusOneRMQ.hpp"

class PMORMQForLCA {
  protected:
    int n;
    std::vector<std::pair<int, int>> v;
    PlusMinusOneRMQ<int> RMQ;
  public:
    PMORMQForLCA() = default;
    PMORMQForLCA(const std::vector<std::pair<int, int>>& v_) { init(v_); }
    void init(const std::vector<std::pair<int, int>>& v_) {
        v = v_;
        n = v.size();
        std::vector<int> rmqvec(n);
        rep (i, n) rmqvec[i] = v[i].first;
        RMQ.init(rmqvec);
    }
    std::pair<int, int> prod(int l, int r) const {
        return v[RMQ.prod_idx(l, r)];
    }
};

template<class T> using PMORMQLCA = EulerTour<T, PMORMQForLCA>;

/**
 * @brief PMORMQLCA($\pm1$RMQによるLCA)
 * @docs docs/PMORMQLCA.md
 */