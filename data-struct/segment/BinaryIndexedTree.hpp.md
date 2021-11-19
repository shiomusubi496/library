---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/BinaryIndexedTree.md
    document_title: BinaryIndexedTree(FenwickTree, BIT)
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
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate<class T> class BinaryIndexedTree\
    \ {\n  protected:\n    using F = std::function<T(T, T)>;\n    using G = std::function<T()>;\n\
    \    using H = std::function<T(T)>;\n    F op;\n    G e;\n    H inv;\n    bool\
    \ inv_exits;\n    int n;\n    std::vector<T> data;\n  public:\n    BinaryIndexedTree()\
    \ = default;\n    BinaryIndexedTree(int n_) : BinaryIndexedTree(n_, [](T a, T\
    \ b) -> T { return a + b; }, []() -> T { return 0; }, [](T a) -> T { return -a;\
    \ }) {}\n    BinaryIndexedTree(int n_, const F& op, const G& e) : op(op), e(e),\
    \ inv_exits(false) { init(n_); }\n    BinaryIndexedTree(int n_, const F& op, const\
    \ G& e, const H& inv) : op(op), e(e), inv(inv), inv_exits(true) { init(n_); }\n\
    \    void init(int n_) {\n        n = 1;\n        while (n < n_) n <<= 1;\n  \
    \      data.assign(n + 1, e());\n    }\n    void add(int k, T x) {\n        ++k;\n\
    \        while (k <= n) {\n            data[k] = op(data[k], x);\n           \
    \ k += k & -k;\n        }\n    }\n    T sum(int k) const {\n        assert(0 <=\
    \ k && k <= n);\n        T res = e();\n        while (k) {\n            res =\
    \ op(res, data[k]);\n            k -= k & -k;\n        }\n        return res;\n\
    \    }\n    T sum(int l, int r) const {\n        assert(l <= r);\n        assert(inv_exits);\n\
    \        return op(sum(r), inv(sum(l)));\n    }\n    T get(int k) const {\n  \
    \      return sum(k, k + 1);\n    }\n    void set(int k, T x) {\n        add(k,\
    \ op(x, inv(get(k))));\n    }\n    template<class C> int max_right(int l, const\
    \ C& cond) {\n        assert(0 <= l && l <= n);\n        assert(cond(e()));\n\
    \        if (l == n) return n;\n        T sm = e();\n        ++l;\n        while\
    \ (l <= n) {\n            if (!cond(op(sm, data[l]))) {\n                int ln\
    \ = l & -l;\n                while (ln >>= 1) {\n                    if (cond(op(sm,\
    \ data[l - ln]))) sm = op(sm, data[l - ln]);\n                    else l -= ln;\n\
    \                }\n                return l;\n            }\n            sm =\
    \ op(sm, data[l]);\n            l += l & -l;\n        }\n        return n;\n \
    \   }\n};\n\n/**\n * @brief BinaryIndexedTree(FenwickTree, BIT)\n * @docs docs/BinaryIndexedTree.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-struct/segment/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-struct/segment/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/data-struct/segment/BinaryIndexedTree.hpp
- /library/data-struct/segment/BinaryIndexedTree.hpp.html
title: BinaryIndexedTree(FenwickTree, BIT)
---
## 概要

一点加算区間和クエリを高速に扱えるデータ構造。必要なところのみ見るため、セグ木より高速。二項演算 $\cdot$ は以下の条件を満たす必要がある。

- 結合則 : 任意の $A, B, C$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e$ が存在して、任意の $A$ に対して $A \cdot e = e \cdot A = A$

min/max などが扱える。

- `BinaryIndexedTree(int n, T op(T, T), T e())` : サイズ `n` の BIT を作成する。 $O(n)$ 。
- `void add(int k, T x)` : `a[k]` に `op(a[k], x)` を代入する。 $O(\log n)$ 。
- `T sum(int k)` : `op(a[0], a[1], ..., a[k-1])` を返す。 $O(\log n)$ 。
- `int max_right(int l, bool f(T))` : BIT 上で二分探索をする。詳しくはセグ木を参照。 $O(\log n)$ 。

また、以下の条件を満たすと、さらに多くのことができる。

- 逆元の存在 : 任意の $A$ に対して、 $A \cdot B = e$ なる $B$ が存在する

足し算や bitwise xor などはこれを満たす。

- `BinaryIndexedTree(int n, T op(T, T), T e(), T inv(T))` : サイズ `n` の BIT を作成する。 $O(n)$ 。
- `T sum(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(\log n)$ 。
- `T get(int k)` : `a[k]` を返す。 $O(\log n)$ 。
- `void set(int k, T x)` : `a[k]` に `x` を代入する。 $O(\log n)$ 。
