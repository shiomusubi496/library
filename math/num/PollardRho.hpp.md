---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/PollardRho.md
    document_title: "PollardRho(\u7D20\u56E0\u6570\u5206\u89E3)"
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
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n#include \"../random/Random.hpp\"\
    \n#include \"MontgomeryModInt.hpp\"\n#include \"num/MillerRabin.hpp\"\n#include\
    \ \"../string/RunLength.hpp\"\n\ntemplate<class T, class Rnd> ull pollard_rho(ull\
    \ n, Rnd& rnd) {\n    if (~n & 1) return 2;\n    if (T::get_mod() != n) T::set_mod(n);\n\
    \    T c, one = 1;\n    auto f = [&](T x) -> T { return x * x + c; };\n    constexpr\
    \ int M = 128;\n    while (1) {\n        c = rnd.uniform(1ull, n - 1);\n     \
    \   T x = rnd.uniform(2ull, n - 1), y = x;\n        ull g = 1;\n        while\
    \ (g == 1) {\n            T p = one, tx = x, ty = y;\n            rep (M) {\n\
    \                x = f(x);\n                y = f(f(y));\n                p *=\
    \ x - y;\n            }\n            g = gcd(p.get(), n);\n            if (g ==\
    \ 1) continue;\n            rep (M) {\n                tx = f(tx);\n         \
    \       ty = f(f(ty));\n                g = gcd((tx - ty).get(), n);\n       \
    \         if (g != 1) {\n                    if (g != n) return g;\n         \
    \           break;\n                }\n            }\n        }\n    }\n    return\
    \ -1;\n}\n\ntemplate<class T = MontgomeryModInt<ull, -3>, class Rnd = Random64>\n\
    std::vector<ull> factorize(ull n, Rnd& rnd = rand64) {\n    if (n == 1) return\
    \ {};\n    std::vector<ull> res;\n    std::vector<ull> st = {n};\n    while (!st.empty())\
    \ {\n        ull t = st.back();\n        st.pop_back();\n        if (t == 1) continue;\n\
    \        if (is_prime_mr(t)) {\n            res.push_back(t);\n            continue;\n\
    \        }\n        ull f = pollard_rho<T>(t, rnd);\n        st.push_back(f);\n\
    \        st.push_back(t / f);\n    }\n    std::sort(all(res));\n    return res;\n\
    }\n\ntemplate<class T = MontgomeryModInt<ull, -3>, class Rnd = Random64>\nstd::vector<std::pair<ull,\
    \ int>> expfactorize(ull n, Rnd& rnd = rand64) {\n    auto f = factorize<T, Rnd>(n,\
    \ rnd);\n    return RunLength(f);\n}\n\nstd::vector<ll> divisors_pr(ll n) {\n\
    \    std::vector<ll> res;\n    auto r = expfactorize(n);\n    int m = r.size();\n\
    \    rec_lambda([&](auto&& self, int k, ll d) -> void {\n        if (k == m) {\n\
    \            res.push_back(d);\n            return;\n        }\n        ll t =\
    \ d;\n        rep (r[k].second) {\n            self(k + 1, d);\n            d\
    \ *= r[k].first;\n        }\n        self(k + 1, d);\n        d = t;\n    })(0,\
    \ 1);\n    std::sort(all(res));\n    return res;\n}\n\n/**\n * @brief PollardRho(\u7D20\
    \u56E0\u6570\u5206\u89E3)\n * @docs docs/math/num/PollardRho.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/PollardRho.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/PollardRho.hpp
layout: document
redirect_from:
- /library/math/num/PollardRho.hpp
- /library/math/num/PollardRho.hpp.html
title: "PollardRho(\u7D20\u56E0\u6570\u5206\u89E3)"
---
## 概要

素因数分解を高速に行う。フロイドの循環検出法に基づいている。

- `vector<ull> factorize(ull n)` : `n` を素因数分解し、昇順に素因数を返す。期待 $O(\sqrt[4]{n})$ であると言われている。
- `vector<pair<ull, int>> expfactorize(ull n)` : `n` を素因数分解したものを素冪の積の形で返す。
- `vector<ll> divisors_pr(ll n)` : `n` の約数を昇順に返す。 $n$ の約数の個数に比例する計算量がかかる。
