#pragma once

#include "../../other/template.hpp"
#include "../../other/monoid.hpp"
#include "../../random/Random.hpp"

using M = Monoid::Max<ll>;
using T = typename M::value_type;
using Rand = Random32;
constexpr int MAX_LEVEL = 30;

class SkipList {
  protected:
    struct Node;
    using Node_ptr = std::shared_ptr<Node>;
    struct Node {
        T val;
        int level;
        std::vector<std::tuple<Node_ptr, int, T>> nxt, prv;
        Node(T x, Rand &rnd) : val(x) {
            level = 1;
            while (level < 30 && (rnd() & 1)) ++level;
            nxt.assign(level, {Node_ptr{}, -1, M::id()});
            prv.assign(level, {Node_ptr{}, -1, M::id()});
        }
        Node(int L) : level(L) {
            nxt.assign(level, {Node_ptr{}, -1, M::id()});
            prv.assign(level, {Node_ptr{}, -1, M::id()});
        }
    };
    Rand rnd;
    Node_ptr fptr, bptr;
  public:
    SkipList() : SkipList(Rand()) {}
    SkipList(const Rand &rnd) : rnd(rnd)
                              , fptr(std::make_shared<Node>(MAX_LEVEL))
                              , bptr(std::make_shared<Node>(MAX_LEVEL)) {
        rep(i, MAX_LEVEL) fptr->nxt[i] = {bptr, 0, M::id()};
        rep(i, MAX_LEVEL) bptr->prv[i] = {fptr, 0, M::id()};
    }
};

/**
 * @brief SkipList
 * @docs docs/SkipList.md
 */
