---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/UnionFind.md
    document_title: UnionFind
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../template.hpp\"\n\nclass UnionFind {\n  protected:\n\
    \    int n;\n    std::vector<int> par_vec;\n  public:\n    UnionFind() : UnionFind(0)\
    \ {}\n    UnionFind(int n) : n(n), par_vec(n, -1) {}\n    int find(int x) {\n\
    \        assert(0 <= x && x < n);\n        return par_vec[x] < 0 ? x : par_vec[x]\
    \ = find(par_vec[x]);\n    }\n    bool merge(int x, int y) {\n        x = find(x);\n\
    \        y = find(y);\n        if (x == y) return false;\n        if (par_vec[x]\
    \ > par_vec[y]) std::swap(x, y);\n        par_vec[x] += par_vec[y];\n        par_vec[y]\
    \ = x;\n        return true;\n    }\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n    int size(int x) {\n        return -par_vec[find(x)];\n\
    \    }\n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(n);\n        rep(i, n) res[find(i)].push_back(i);\n        res.erase(\n\
    \            remove_if(res.begin(), res.end(),\n                      [](const\
    \ std::vector<int>& v) { return v.empty(); }),\n            res.end());\n    \
    \    return res;\n    }\n    bool is_root(int x) const {\n        assert(0 <=\
    \ x && x < n);\n        return par_vec[x] < 0;\n    }\n};\n\n/**\n * @brief UnionFind\n\
    \ * @docs docs/UnionFind.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-struct/unionfind/UnionFind.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-struct/unionfind/UnionFind.hpp
layout: document
redirect_from:
- /library/data-struct/unionfind/UnionFind.hpp
- /library/data-struct/unionfind/UnionFind.hpp.html
title: UnionFind
---
## 概要

集合を併合する操作や、ある要素が属する集合の代表元を問い合わせる操作を行える。

- `bool merge(int x, int y)` :  
要素 `x` の属する集合と要素 `y` の属する集合を併合する。もともと同じ集合に属していたなら `false` を、そうでないなら `true` を返す。ならし $O(\alpha(N))$ 。

- `int find(int x)` :  
要素 `x` の属する集合の代表元を返す。ならし $O(\alpha(N))$ 。

- `bool same(int x, int y)`  
要素 `x` と要素 `y` が同じ集合に属するかを判定する。ならし $O(\alpha(N))$ 。

- `int size(int x)`  
要素 `x` の属する集合の要素数を返す。ならし $O(\alpha(N))$ 。

- `bool is_root(int x)`  
要素 `x` が属する集合の代表元が `x` であるかを返す。 $O(1)$ 。

- `vector<vector<int>> groups()`  
「「集合に属する要素のリスト」のリスト」を返す。ならし $O(N\alpha(N))$ 。
