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
    \n#include \"GaussianInteger.hpp\"\n\nstd::pair<ll, ll> two_square_sum_prime(ll\
    \ p) {\n    assert(p == 2 || p % 4 == 1);\n    if (p == 2) return {1, 1};\n  \
    \  auto mod_pow_ll = [&](i128 x, ll e) -> i128 {\n        i128 res = 1;\n    \
    \    while (e) {\n            if (e & 1) (res *= x) %= p;\n            (x *= x)\
    \ %= p;\n            e /= 2;\n        }\n        return res;\n    };\n    ll x\
    \ = 1;\n    while (1) {\n        ++x;\n        ll t = mod_pow_ll(x, (p - 1) /\
    \ 4);\n        if (i128{t} * t % p == p - 1) {\n            x = t;\n         \
    \   break;\n        }\n    }\n    GaussianInteger<i128> a(p, 0), b(x, 1);\n  \
    \  a = gcd(a, b);\n    assert(a.norm() == p);\n    return {a.real, a.imag};\n\
    }\n\ntemplate<class T> std::vector<std::pair<T, T>> two_square_sum(T a) {\n  \
    \  if (a < 0) return {};\n    if (a == 0) return {{0, 0}};\n    using G = GaussianInteger<T>;\n\
    \    const auto& pfs = expfactorize(a);\n    for (const auto& [p, e] : pfs) {\n\
    \        if (p % 4 == 3 && e % 2 == 1) return {};\n    }\n    std::vector<G> res{{1,\
    \ 0}};\n    for (const auto& [p, e] : pfs) {\n        if (p % 4 == 3) {\n    \
    \        const T x = my_pow(p, e / 2);\n            for (auto& g : res) {\n  \
    \              g.real *= x;\n                g.imag *= x;\n            }\n   \
    \         continue;\n        }\n        auto [px, py] = two_square_sum_prime(p);\n\
    \        G pg(px, py);\n        std::vector<G> gpows(e + 1);\n        gpows[0]\
    \ = 1;\n        rep (i, e) gpows[i + 1] = gpows[i] * pg;\n        if (p == 2)\
    \ {\n            for (auto&& g : res) g *= gpows[e];\n            continue;\n\
    \        }\n        std::vector<G> gs(e + 1);\n        rep (i, e + 1) gs[i] =\
    \ gpows[i] * gpows[e - i].conj();\n        std::vector<G> nres;\n        for (auto\
    \ g : gs) for (auto i : res) nres.push_back(g * i);\n        res = std::move(nres);\n\
    \    }\n    for (auto&& g : res) {\n        while (g.real <= 0 || g.imag < 0)\
    \ g = {-g.imag, g.real};\n    }\n    std::vector<std::pair<T, T>> ans(res.size());\n\
    \    rep (i, res.size()) ans[i] = {res[i].real, res[i].imag};\n    return ans;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/TwoSquareSum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/TwoSquareSum.hpp
layout: document
redirect_from:
- /library/math/num/TwoSquareSum.hpp
- /library/math/num/TwoSquareSum.hpp.html
title: math/num/TwoSquareSum.hpp
---
