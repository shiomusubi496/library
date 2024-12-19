---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/ChineseRemainder.md
    document_title: "Chinese Remainder(\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
    links:
    - https://qiita.com/drken/items/ae02240cd1f8edfc86fd
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
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n\nPLL ChineseRemainder(ll\
    \ b1, ll m1, ll b2, ll m2) {\n    const PLL p = extGCD(m1, m2);\n    const ll\
    \ g = p.first * m1 + p.second * m2;\n    const ll l = m1 / g * m2;\n    if ((b2\
    \ - b1) % g != 0) return PLL{-1, -1};\n    const ll x = (b2 - b1) / g * p.first\
    \ % (m2 / g);\n    return {(x * m1 + b1 + l) % l, l};\n}\nPLL ChineseRemainder(const\
    \ std::vector<ll>& b, const std::vector<ll>& m) {\n    PLL res{0, 1};\n    rep\
    \ (i, b.size()) {\n        res = ChineseRemainder(res.first, res.second, b[i],\
    \ m[i]);\n        if (res.first == -1) return res;\n    }\n    return res;\n}\n\
    \nPLL Garner(std::vector<ll> b, std::vector<ll> m, ll MOD) {\n    const int n\
    \ = b.size();\n    rep (i, n) {\n        rep (j, i) {\n            ll g = gcd(m[i],\
    \ m[j]);\n            if ((b[i] - b[j]) % g != 0) return PLL{-1, -1};\n      \
    \      m[i] /= g;\n            m[j] /= g;\n            ll gi = gcd(m[i], g), gj\
    \ = g / gi;\n            for (g = gcd(gi, gj); g != 1; g = gcd(gi, gj)) {\n  \
    \              gi *= g;\n                gj /= g;\n            }\n           \
    \ m[i] *= gi;\n            m[j] *= gj;\n            b[i] %= m[i];\n          \
    \  b[j] %= m[j];\n        }\n    }\n    m.push_back(MOD);\n    std::vector<ll>\
    \ ans(n + 1), pr(n + 1, 1);\n    rep (i, n) {\n        ll t = (b[i] - ans[i])\
    \ * mod_inv(pr[i], m[i]) % m[i];\n        if (t < 0) t += m[i];\n        rep (j,\
    \ i + 1, n + 1) {\n            (ans[j] += t * pr[j]) %= m[j];\n            (pr[j]\
    \ *= m[i]) %= m[j];\n        }\n    }\n    return {ans[n], pr[n]};\n}\n\n/**\n\
    \ * @brief Chinese Remainder(\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)\n * @docs docs/math/num/ChineseRemainder.md\n\
    \ * @see https://qiita.com/drken/items/ae02240cd1f8edfc86fd\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/ChineseRemainder.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/ChineseRemainder.hpp
layout: document
redirect_from:
- /library/math/num/ChineseRemainder.hpp
- /library/math/num/ChineseRemainder.hpp.html
title: "Chinese Remainder(\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
---
## 概要

$b_0, b_1, m_0, m_1$ が与えられたとき、 $M = \mathrm{lcm}(m_0, m_1)$ として、 $\left\{\begin{array}{l} x \equiv b_0 \pmod{m_0} \\ x \equiv b_1 \pmod{m_1} \\ \end{array} \right.$ を満たす $0 \leq x < M$ を見つけ $(x, M)$ の組を返す。

ただし、 $b_0 \not\equiv b_1 \pmod{\gcd(m_0, m_1)}$ のときこのような $x$ は存在しないため、 $(-1, -1)$ を返す。

$m_0, m_1$ が互いに素 (つまり $m_0 m_1 = M$) であるときこのような $x$ は必ず存在し、また一意であることで知られている。

- `PLL ChineseRemainder(ll b0, ll m0, ll b1, ll m1)` : 上記の通り。拡張ユークリッドの互除法を用いている。 $O(\log(m0 + m1))$ 。
- `PLL ChineseRemainder(vector<ll> b, vector<ll> m)` : 同様。 $O(n \log\max(m))$ 。
- `PLL Garner(vector<ll> b, vector<ll> m, ll MOD)` : 同様に $\mod MOD$ で求める。 $O(n^2 \log\max(m))$ 。
