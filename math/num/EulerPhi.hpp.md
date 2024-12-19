---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/EulerPhi.md
    document_title: "Euler's-Phi(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)"
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
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n#include \"num/PollardRho.hpp\"\
    \n\nll euler_phi(ll n) {\n    ll res = n;\n    for (ll i = 2; i * i <= n; ++i)\
    \ {\n        if (n % i == 0) {\n            res = res / i * (i - 1);\n       \
    \     while (n % i == 0) n /= i;\n        }\n    }\n    if (n != 1) res = res\
    \ / n * (n - 1);\n    return res;\n}\n\nll euler_phi_pollardrho(ll n) {\n    for\
    \ (auto p : expfactorize(n)) n = n / p.first * (p.first - 1);\n    return n;\n\
    }\n\nclass EulerPhi {\nprivate:\n    ll MAX;\n    std::vector<ll> data;\n\npublic:\n\
    \    EulerPhi(ll MAX) : MAX(MAX), data(MAX + 1, 0) {\n        rep (i, MAX + 1)\
    \ data[i] = i;\n        rep (i, 2, MAX + 1) {\n            if (data[i] != i) continue;\n\
    \            rep (j, i, MAX + 1, i) {\n                data[j] = data[j] / i *\
    \ (i - 1);\n            }\n        }\n    }\n    ll phi(ll x) { return data[x];\
    \ }\n};\n\n/**\n * @brief Euler's-Phi(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\
    \u6570)\n * @docs docs/math/num/EulerPhi.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/EulerPhi.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/EulerPhi.hpp
layout: document
redirect_from:
- /library/math/num/EulerPhi.hpp
- /library/math/num/EulerPhi.hpp.html
title: "Euler's-Phi(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)"
---
## 概要

オイラーの $\phi$ 関数。読み方はトーシェント、ファイなど。

- `ll euler_phi(ll N)` : $\phi(N)$ を返す。 $\Theta(\sqrt N)$ 。
- `ll euler_phi_pollardrho(ll N)` : $\phi(N)$ を返す。素因数分解に Pollard の Rho 法を用いている。計算量は PollardRho 参照。

また、エラトステネスの篩を応用して、多くのクエリに効率よく答えることもできる。

- `EulerPhi(ll N)` : `N` 以下の $\phi$ 関数のテーブルを作る。 $\Theta(N\log\log N)$ 。
- `ll phi(ll x)` : $\phi(x)$ を返す。 $\Theta(1)$ 。
