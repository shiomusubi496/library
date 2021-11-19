---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/DisjointSparseTable.md
    document_title: DisjointSparseTable
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
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate<class T> class DisjointSparseTable\
    \ {\n  protected:\n    using F = std::function<T(T, T)>;\n    int h;\n    F op;\n\
    \    std::vector<int> logtable;\n    std::vector<std::vector<T>> data;\n  public:\n\
    \    DisjointSparseTable() = default;\n    DisjointSparseTable(const std::vector<T>&\
    \ v, const F& op) : op(op) { init(v); }\n    void init(const std::vector<T>& v)\
    \ {\n        h = 1;\n        while ((1 << h) < (int)v.size()) ++h;\n        logtable.assign(1\
    \ << h, 0);\n        rep (i, 2, 1 << h) logtable[i] = logtable[i >> 1] + 1;\n\
    \        data.assign(h, std::vector<T>(1 << h));\n        rep (i, v.size()) data[0][i]\
    \ = v[i];\n        rep (i, 1, h) {\n            int len = 1 << i;\n          \
    \  rep (j, len, v.size(), len << 1) {\n                data[i][j - 1] = v[j -\
    \ 1];\n                rep (k, 1, len) data[i][j - k - 1] = op(v[j - k - 1], data[i][j\
    \ - k]);\n                data[i][j] = v[j];\n                rep (k, 1, len)\
    \ {\n                    if (j + k >= (int)v.size()) break;\n                \
    \    data[i][j + k] = op(data[i][j + k - 1], v[j + k]);\n                }\n \
    \           }\n        }\n    }\n    T query(int l, int r) {\n        assert(0\
    \ <= l && l < r && r <= (1 << h));\n        --r;\n        if (l == r) return data[0][l];\n\
    \        int d = logtable[l ^ r];\n        return op(data[d][l], data[d][r]);\n\
    \    }\n};\n\n/**\n * @brief DisjointSparseTable\n * @docs docs/DisjointSparseTable.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-struct/segment/DisjointSparseTable.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-struct/segment/DisjointSparseTable.hpp
layout: document
redirect_from:
- /library/data-struct/segment/DisjointSparseTable.hpp
- /library/data-struct/segment/DisjointSparseTable.hpp.html
title: DisjointSparseTable
---
## 概要

区間最小値などの区間に対するクエリを扱える。ただし、二項演算子 $\cdot$ は以下の条件を満たす必要がある。

- 結合則 : 任意の $A, B, C$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$

`SparseTable` より制約が弱く、足し算など多くの演算が使える。

以下の計算量は `op` が定数時間で動くと仮定したもの。 `op` 内部の計算量が $O(f(n))$ の時、以下の計算量は全て $O(f(n))$ 倍になる。

- `DisjointSparseTable(vector<int> a, T op(T, T))` : リスト `a` と二項演算 `op` で初期化する。 $N=\mathrm{len}(a)$ として $O(N \log N)$ 。
- `T query(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(1)$ 。
