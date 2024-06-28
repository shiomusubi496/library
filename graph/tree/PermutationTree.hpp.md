---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/78898
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data-struct/segment/StarrySkyTree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../../other/monoid.hpp\"\
    \n#include \"../../data-struct/segment/StarrySkyTree.hpp\"\n#include \"../Graph.hpp\"\
    \n\nclass PermutationTree {\nprivate:\n    struct Node {\n        int l, r;\n\
    \        int mn, mx;\n        int type; // 0 : prime, 1 : asc, -1 : desc\n   \
    \     int par;\n        Node() : l(1 << 30), r(-1), mn(1 << 30), mx(-1), type(0),\
    \ par(-1) {}\n        Node(int l, int r, int m, int M, int t, int p)\n       \
    \     : l(l), r(r), mn(m), mx(M), type(t), par(p) {}\n    };\n    std::vector<Node>\
    \ nodes;\n\n    void add_child(int v, int p) {\n        nodes[v].par = p;\n  \
    \      chmin(nodes[p].l, nodes[v].l);\n        chmax(nodes[p].r, nodes[v].r);\n\
    \        chmin(nodes[p].mn, nodes[v].mn);\n        chmax(nodes[p].mx, nodes[v].mx);\n\
    \    }\n\npublic:\n    PermutationTree(const std::vector<int>& p) {\n        int\
    \ n = p.size();\n        std::vector<int> st;\n        st.reserve(2 * n);\n  \
    \      nodes.reserve(2 * n);\n        nodes.resize(n);\n        rep (i, n) nodes[i]\
    \ = {(int)i, (int)i + 1, p[i], p[i] + 1, 0, -1};\n        // RangeAddQueryRangeMinimumQuery<int>\
    \ seg(n, 0);\n        StarrySkyTree<Monoid::AddMin<int>> seg(n, 0);\n        std::vector<int>\
    \ mxs{-1}, mns{-1};\n        mxs.reserve(n);\n        mns.reserve(n);\n      \
    \  rep (i, n) {\n            while (mxs.back() != -1 && p[mxs.back()] < p[i])\
    \ {\n                seg.apply(mxs[mxs.size() - 2] + 1, mxs.back() + 1,\n    \
    \                      p[i] - p[mxs.back()]);\n                mxs.pop_back();\n\
    \            }\n            while (mns.back() != -1 && p[mns.back()] > p[i]) {\n\
    \                seg.apply(mns[mns.size() - 2] + 1, mns.back() + 1,\n        \
    \                  p[mns.back()] - p[i]);\n                mns.pop_back();\n \
    \           }\n            mxs.push_back(i);\n            mns.push_back(i);\n\
    \            seg.apply(0, i, -1);\n            int cur = i;\n            while\
    \ (!st.empty()) {\n                int t = st.back();\n                if ((nodes[t].type\
    \ == 1 && nodes[t].mx == nodes[cur].mn) ||\n                    (nodes[t].type\
    \ == -1 && nodes[t].mn == nodes[cur].mx)) {\n                    add_child(cur,\
    \ t);\n                    st.pop_back();\n                    cur = t;\n    \
    \            }\n                else if (nodes[t].mx == nodes[cur].mn ||\n   \
    \                      nodes[t].mn == nodes[cur].mx) {\n                    int\
    \ p = nodes.size();\n                    nodes.emplace_back();\n             \
    \       nodes[p].type = nodes[t].mx == nodes[cur].mn ? 1 : -1;\n             \
    \       add_child(cur, p);\n                    add_child(t, p);\n           \
    \         st.pop_back();\n                    cur = p;\n                }\n  \
    \              else if (seg.prod(0, nodes[cur].l) == 0) {\n                  \
    \  int p = nodes.size();\n                    nodes.emplace_back();\n        \
    \            nodes[p].type = 0;\n                    add_child(cur, p);\n    \
    \                do {\n                        add_child(st.back(), p);\n    \
    \                    st.pop_back();\n                    } while (nodes[p].r -\
    \ nodes[p].l !=\n                             nodes[p].mx - nodes[p].mn);\n  \
    \                  cur = p;\n                }\n                else {\n     \
    \               break;\n                }\n            }\n            st.push_back(cur);\n\
    \        }\n        rep (i, n) nodes[i].type = 1;\n    }\n\n    int par(int v)\
    \ const { return nodes[v].par; }\n    int l(int v) const { return nodes[v].l;\
    \ }\n    int r(int v) const { return nodes[v].r; }\n    int mn(int v) const {\
    \ return nodes[v].mn; }\n    int mx(int v) const { return nodes[v].mx; }\n   \
    \ int type(int v) const { return nodes[v].type; }\n    bool is_linear(int v) const\
    \ { return nodes[v].type != 0; }\n    bool is_prime(int v) const { return nodes[v].type\
    \ == 0; }\n    int size() const { return nodes.size(); }\n    UnweightedGraph\
    \ tree() const {\n        int n = nodes.size();\n        UnweightedGraph g(n);\n\
    \        rep (i, n)\n            if (nodes[i].par != -1) {\n                g.add_edge(nodes[i].par,\
    \ i, true);\n            }\n        return g;\n    }\n    int root() const { return\
    \ nodes.size() - 1; }\n};\n\n/**\n * @see https://codeforces.com/blog/entry/78898\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/PermutationTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/PermutationTree.hpp
layout: document
redirect_from:
- /library/graph/tree/PermutationTree.hpp
- /library/graph/tree/PermutationTree.hpp.html
title: graph/tree/PermutationTree.hpp
---
