---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/Divisors.md
    document_title: "Divisors(\u7D04\u6570\u5217\u6319)"
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
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n\nstd::vector<ll> divisors(ll\
    \ n) {\n    std::vector<ll> res1, res2;\n    for (ll i = 1; i * i <= n; ++i) {\n\
    \        if (n % i == 0) {\n            res1.push_back(i);\n            if (i\
    \ * i != n) res2.push_back(n / i);\n        }\n    }\n    res1.reserve(res1.size()\
    \ + res2.size());\n    std::copy(res2.rbegin(), res2.rend(), std::back_inserter(res1));\n\
    \    return res1;\n}\n\n/**\n * @brief Divisors(\u7D04\u6570\u5217\u6319)\n *\
    \ @docs docs/math/num/Divisors.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/Divisors.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/Divisors.hpp
layout: document
redirect_from:
- /library/math/num/Divisors.hpp
- /library/math/num/Divisors.hpp.html
title: "Divisors(\u7D04\u6570\u5217\u6319)"
---
## 概要

- `vector<ll> divisors(ll n)` : $n$ の約数を昇順に返す。 $\Theta(\sqrt{n})$ 。
