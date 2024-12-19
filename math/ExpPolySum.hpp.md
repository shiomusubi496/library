---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/ExpPolySum.md
    document_title: ExpPolySum($\sum_{i=0}^{\infty}r^ii^d$)
    links:
    - https://kyopro-friends.hatenablog.com/entry/2020/03/11/073122
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../other/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n#include \"Combinatorics.hpp\"\
    \n#include \"poly/SamplingPointsShift.hpp\"\n#include \"PowEnumerate.hpp\"\n\n\
    template<class T, class Comb = Combinatorics<T>>\nT exp_poly_sum(T r, int d, ll\
    \ n = -1) {\n    if (n == -1) assert(r != 1);\n    auto cum = pow_enumerate<T>(d\
    \ + 1, d);\n    Comb::init(d + 1);\n    T c = 0;\n    {\n        T sm = 0, cur\
    \ = 1;\n        rep (i, d + 2) {\n            sm += cur * cum[i];\n          \
    \  cur *= r;\n            cum[i] = sm;\n        }\n    }\n    {\n        T t =\
    \ 1;\n        rep (i, d + 1) {\n            c += t * Comb::comb(d + 1, i) * cum[d\
    \ - i];\n            t *= -r;\n        }\n        c /= (1 - r).pow(d + 1);\n \
    \   }\n    if (n == -1) return c;\n    if (n == 0) return 0;\n    if (r == 1)\
    \ return sampling_points_shift<T, Comb>(cum, n - 1);\n    cum.pop_back();\n  \
    \  T iv = 1 / r, cur = 1;\n    rep (i, d + 1) {\n        cum[i] = (c - cum[i])\
    \ * cur;\n        cur *= iv;\n    }\n    return c - r.pow(n - 1) * sampling_points_shift<T,\
    \ Comb>(cum, n - 1);\n}\n\n/**\n * @brief ExpPolySum($\\sum_{i=0}^{\\infty}r^ii^d$)\n\
    \ * @docs docs/math/ExpPolySum.md\n * @see https://kyopro-friends.hatenablog.com/entry/2020/03/11/073122\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ExpPolySum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ExpPolySum.hpp
layout: document
redirect_from:
- /library/math/ExpPolySum.hpp
- /library/math/ExpPolySum.hpp.html
title: ExpPolySum($\sum_{i=0}^{\infty}r^ii^d$)
---
## 概要

$\displaystyle \sum_{i=0}^{\infty} r^ii^d = \sum_{i=0}^d(-r)^i\binom{d+1}{i}\sum_{j=0}^{d-i}r^jj^d$ なので、線形時間で計算できる。

- `T exp_poly_sum(T r, int d, int n = -1)` : $n=-1$ のとき上記の値を返す。 $r \neq 1$ でなければならない。 $\Theta(n)$ 。

$$\begin{align*}
\displaystyle \sum_{i=0}^{n-1} r^ii^d &= \sum_{i=0}^{\infty} r^ii^d - \sum_{i=n}^{\infty} r^ii^d \\
 &= \sum_{i=0}^{\infty} r^ii^d - r^n \sum_{i=0}^{\infty} r^i(i+n)^d
\end{align*}$$

で、第一項は前述の通り計算でき、第二項$/ r^n$ は $(i+n)^d$ を展開すると $n$ の $d$ 次多項式になることが分かるため、 $0$ から $d$ についての値を求めれば標本点シフトできる。

$r=1$ のときはうまくいかないので普通にやる。

- `T exp_poly_sum(T r, int d, int n = -1)` : $n\neq-1$ のとき上記の値を返す。 $\Theta(n)$ 。
