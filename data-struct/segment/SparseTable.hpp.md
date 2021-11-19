---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/SparseTable.md
    document_title: SparseTable
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
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate<class T> class SparseTable\
    \ {\n  protected:\n    using F = std::function<T(T, T)>;\n    int h;\n    F op;\n\
    \    std::vector<int> logtable;\n    std::vector<std::vector<T>> data;\n  public:\n\
    \    SparseTable() = default;\n    SparseTable(const std::vector<T>& v, const\
    \ F& op) : op(op) { init(v); }\n    void init(const std::vector<T>& v) {\n   \
    \     h = 1;\n        while ((1 << h) < (int)v.size()) ++h;\n        logtable.assign((1\
    \ << h) + 1, 0);\n        reps (i, 1, 1 << h) logtable[i] = logtable[i >> 1] +\
    \ 1;\n        data.assign(h + 1, std::vector<T>(1 << h));\n        rep (i, v.size())\
    \ data[0][i] = v[i];\n        rep (i, h) {\n            rep (j, (1 << h) - (1\
    \ << i)) {\n                data[i + 1][j] = op(data[i][j], data[i][j + (1 <<\
    \ i)]);\n            }\n        }\n    }\n    T query(int l, int r) {\n      \
    \  assert(0 <= l && l < r && r <= (1 << h));\n        int d = logtable[r - l];\n\
    \        return op(data[d][l], data[d][r - (1 << d)]);\n    }\n};\n\n/**\n * @brief\
    \ SparseTable\n * @docs docs/SparseTable.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-struct/segment/SparseTable.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-struct/segment/SparseTable.hpp
layout: document
redirect_from:
- /library/data-struct/segment/SparseTable.hpp
- /library/data-struct/segment/SparseTable.hpp.html
title: SparseTable
---
## 概要

区間最小値/最大値などの区間に対するクエリを扱える。ただし、二項演算子 $\cdot$ は以下の条件を満たす必要がある。

- 結合則 : 任意の $A, B, C$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 冪等性 : 任意の $A$ に対して $A \cdot A = A$

例えば、 `max, min, gcd, lcm` などがこの条件を満たす。

以下の計算量は `op` が定数時間で動くと仮定したもの。 `op` 内部の計算量が $O(f(n))$ の時、以下の計算量は全て $O(f(n))$ 倍になる。

- `SparseTable(vector<int> a, T op(T, T))` : リスト `a` と二項演算 `op` で初期化する。 $N=\mathrm{len}(a)$ として $O(N \log N)$ 。
- `T query(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(1)$ 。
