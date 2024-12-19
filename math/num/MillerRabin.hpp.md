---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/MillerRabin.md
    document_title: "MillerRabin(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\
      \u5B9A)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../other/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n#include \"MontgomeryModInt.hpp\"\
    \n\nconstexpr ull base_miller_rabin_int[3] = {2, 7, 61};\nconstexpr ull base_miller_rabin_ll[7]\
    \ = {2,      325,     9375,      28178,\n                                    \
    \     450775, 9780504, 1795265022};\n\ntemplate<class T> constexpr bool miller_rabin(ull\
    \ n, const ull base[], int s) {\n    if (T::get_mod() != n) T::set_mod(n);\n \
    \   ull d = n - 1;\n    while (~d & 1) d >>= 1;\n    T e{1}, re{n - 1};\n    rep\
    \ (i, s) {\n        ull a = base[i];\n        if (a >= n) return true;\n     \
    \   ull t = d;\n        T y = T(a).pow(t);\n        while (t != n - 1 && y !=\
    \ e && y != re) {\n            y *= y;\n            t <<= 1;\n        }\n    \
    \    if (y != re && !(t & 1)) return false;\n    }\n    return true;\n}\n\nconstexpr\
    \ bool is_prime_mr(ll n) {\n    if (n == 2) return true;\n    if (n < 2 || n %\
    \ 2 == 0) return false;\n    if (n < (1u << 31))\n        return miller_rabin<MontgomeryModInt<unsigned\
    \ int, -2>>(\n            n, base_miller_rabin_int, 3);\n    return miller_rabin<MontgomeryModInt<ull,\
    \ -2>>(n, base_miller_rabin_ll, 7);\n}\n\n#if __cpp_variable_templates >= 201304L\
    \ && __cpp_constexpr >= 201304L\ntemplate<ull n> constexpr bool is_prime_v = is_prime_mr(n);\n\
    #endif\n\n/**\n * @brief MillerRabin(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\
    \u6570\u5224\u5B9A)\n * @docs docs/math/num/MillerRabin.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/MillerRabin.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/MillerRabin.hpp
layout: document
redirect_from:
- /library/math/num/MillerRabin.hpp
- /library/math/num/MillerRabin.hpp.html
title: "MillerRabin(\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A)"
---
## 概要

高速に素数判定を行う。本来確率的アルゴリズムだが、 $2^{63}$ 未満の値について決定的に判定できる。

- `bool is_prime_mr(ll n)` : `n` が素数であるか判定する。 $\Theta(\log n)$ 。
- `constexpr bool is_prime_v<ll n>` : `n` が素数であるかを判定するメタ関数。
