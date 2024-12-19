---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/PowEnumerate.md
    document_title: PowEnumerate
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../other/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n#include \"num/PrimeFactor.hpp\"\
    \n\n// 1/a[i]   O(n + log p)\ntemplate<class T> std::vector<T> inv_enumerate(std::vector<T>\
    \ a) {\n    int n = a.size();\n    std::vector<T> res(n + 1);\n    res[0] = 1;\n\
    \    rep (i, n) res[i + 1] = res[i] * a[i];\n    T iv = 1 / res[n];\n    res.pop_back();\n\
    \    rrep (i, n) {\n        res[i] *= iv;\n        iv *= a[i];\n    }\n    return\
    \ res;\n}\n\n// 0^m, 1^m, ..., n^m   O(n log m / log n)\ntemplate<class T> std::vector<T>\
    \ pow_enumerate(int n, ll m) {\n    if (m == 0) return std::vector<T>(n + 1, 1);\n\
    \    std::vector<T> res(n + 1);\n    res[0] = 0;\n    res[1] = 1;\n    PrimeFactor\
    \ pf(n);\n    rep (i, 2, n + 1) {\n        if (pf.is_prime(i)) res[i] = T{i}.pow(m);\n\
    \        else {\n            ll x = pf.get_factor(i);\n            res[i] = res[x]\
    \ * res[i / x];\n        }\n    }\n    return res;\n}\n\n/**\n * @brief PowEnumerate\n\
    \ * @docs docs/math/PowEnumerate.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: math/PowEnumerate.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/PowEnumerate.hpp
layout: document
redirect_from:
- /library/math/PowEnumerate.hpp
- /library/math/PowEnumerate.hpp.html
title: PowEnumerate
---
## 概要

$a_0, a_1, \ldots, a_{n-1}$ について、 $\prod_i a_i$ の逆数を一度計算するだけで、適当な累積積をかけて全ての逆元を得られる。

- `vector<T> inv_enumerate(vector<T> a)` : $a_0^{-1}, a_1^{-1}, \ldots$ を返す。 $\Theta(n + \log p)$

$i=0, 1, \ldots, n$ について $i^m$ を列挙したいとき、愚直にやると $\Theta(n \log m)$ だが、篩を用いて素数の $i$ のみ $i^m$ を計算し、合成数はそれらの積で上手く計算できる。

- `vector<T> pow_enumerate(int n, ll m = n)` : $\Theta\left(n+\cfrac{n \log m}{\log n}\right)$ (素数定理より)。特に $n=m$ や $n>m$ のとき線形時間になる。
