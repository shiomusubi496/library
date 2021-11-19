---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/CumulativeSum.md
    document_title: "CumulativeSum(\u7D2F\u7A4D\u548C)"
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
  code: "#pragma once\n\n#include \"../template.hpp\"\n\ntemplate<class T> class CumulativeSum\
    \ {\n  protected:\n    using F = std::function<T(T, T)>;\n    using G = std::function<T()>;\n\
    \    using H = std::function<T(T)>;\n    F op;\n    G e;\n    H inv;\n    int\
    \ n;\n    std::vector<T> data;\n  public:\n    CumulativeSum() = default;\n  \
    \  CumulativeSum(const std::vector<T>& v) : CumulativeSum(v, [](T a, T b) -> T\
    \ { return a + b; }, []() -> T { return 0; }, [](T a) -> T { return -a; }) {}\n\
    \    CumulativeSum(const std::vector<T>& v, const F& op, const G& e, const H&\
    \ inv) : op(op), e(e), inv(inv) { init(v); }\n    void init(const std::vector<T>&\
    \ v) {\n        n = v.size();\n        data.assign(n + 1, e());\n        rep (i,\
    \ n) data[i + 1] = op(data[i], v[i]);\n    }\n    T query(int l, int r) {\n  \
    \      assert(0 <= l && l <= r && r <= n);\n        return op(data[r], inv(data[l]));\n\
    \    }\n};\n\n/**\n * @brief CumulativeSum(\u7D2F\u7A4D\u548C)\n * @docs docs/CumulativeSum.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-struct/segment/CumulativeSum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-struct/segment/CumulativeSum.hpp
layout: document
redirect_from:
- /library/data-struct/segment/CumulativeSum.hpp
- /library/data-struct/segment/CumulativeSum.hpp.html
title: "CumulativeSum(\u7D2F\u7A4D\u548C)"
---
## 概要

区間和など区間に対するクエリを扱える。ただし、二項演算子 $\cdot$ は以下の条件を満たす必要がある。

- 結合則 : 任意の $A, B, C$ に対して $(A \cdot B) \cdot C = A \cdot (B \cdot C)$
- 単位元の存在 : ある $e$ が存在して、任意の $A$ に対して $A \cdot e = e \cdot A = A$ が成り立つ。
- 逆元の存在 : 任意の $A$ に対して、 $A \cdot B = e$ となる $B$ が存在する

例えば、足し算や bitwise xor などがこの条件を満たす。

以下の計算量は `op` が定数時間で動くと仮定したもの。 `op` 内部の計算量が $O(f(n))$ の時、以下の計算量は全て $O(f(n))$ 倍になる。

- `SparseTable(vector<int> a, T op(T, T), T e(), T inv(T))` : リスト `a` と二項演算 `op` 、単位元を返す `e` 、及び逆元を返す `inv` で初期化する。 $N=\mathrm{len}(a)$ として $O(N)$ 。
- `T query(int l, int r)` : `op(a[l], a[l+1], ..., a[r-1])` を返す。 $O(1)$ 。
