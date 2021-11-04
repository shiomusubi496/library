---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../../template.hpp\"\n\nclass PrimeFactor {\n\
    \  protected:\n    ll MAX;\n    std::vector<ll> era;\n  public:\n    PrimeFactor(ll\
    \ _MAX) : MAX(_MAX), era(MAX + 1, -1) {\n        for (ll i = 2; i <= MAX; ++i)\
    \ {\n            if (era[i] != -1) continue;\n            for (ll j = i; j <=\
    \ MAX; j += i) era[j] = i;\n        }\n    }\n    bool is_prime(ll x) { return\
    \ era[x] == x; }\n    std::vector<ll> factorize(ll x) {\n        std::vector<ll>\
    \ res;\n        for (; x > 1; x /= era[x]) res.push_back(x);\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/PrimeFactor.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/PrimeFactor.hpp
layout: document
redirect_from:
- /library/math/PrimeFactor.hpp
- /library/math/PrimeFactor.hpp.html
title: math/PrimeFactor.hpp
---
