---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/DiscreteLogarithm.md
    document_title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
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
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n#include \"../other/monoid2.hpp\"\
    \n#include \"num/KthRoot.hpp\"\n#include \"BarrettReduction.hpp\"\n\ntemplate<class\
    \ A,\n         class Container = std::unordered_map<typename A::M::value_type,\
    \ ll>>\nll baby_step_giant_step(const typename A::M::value_type& a,\n        \
    \                const typename A::M::value_type& b,\n                       \
    \ const typename A::E::value_type& f, ll MAX) {\n    using T = typename A::M::value_type;\n\
    \    using U = typename A::E::value_type;\n    ll s = kth_root(MAX, 2) + 1;\n\
    \    Container mp;\n    {\n        const U g = A::E::get_inv(f);\n        T x\
    \ = b;\n        rep (i, s) {\n            if (mp.count(x) == 0) mp[x] = i;\n \
    \           x = A::op(g, x);\n        }\n    }\n    {\n        U g = A::E::id();\n\
    \        rep (s) g = A::E::op(g, f);\n        T x = a;\n        rep (i, s) {\n\
    \            if (mp.count(x)) return i * s + mp[x];\n            x = A::op(g,\
    \ x);\n        }\n    }\n    return -1;\n}\n\nnamespace Monoid {\n\ntemplate<class\
    \ T> struct ProductAction {\n    using M = Product<T>;\n    using E = Product<T>;\n\
    \    static T op(T a, T b) { return a * b; }\n};\n\n} // namespace Monoid\n\n\
    template<class T> struct hash_mint_for_discrete_logarithm {\n    std::size_t operator()(const\
    \ T& x) const {\n        return std::hash<unsigned int>()(x.get());\n    }\n};\n\
    \n// min k (a*x^k=b)\ntemplate<class T> ll discrete_logarithm_mint(T a, T x, T\
    \ b) {\n    return baby_step_giant_step<\n        Monoid::ProductAction<T>,\n\
    \        std::unordered_map<T, ll, hash_mint_for_discrete_logarithm<T>>>(\n  \
    \      a, b, x, T::get_mod());\n}\n\ntemplate<class T> ll discrete_logarithm_mint(T\
    \ x, T b) {\n    return discrete_logarithm_mint<T>(T{1}, x, b);\n}\n\n// min k\
    \ (a*x^k = b (mod m))\nll discrete_logarithm(ll a, ll x, ll b, ll m) {\n    if\
    \ (a == b) return 0;\n\n    ll g = 1, tmp = x;\n    int cnt = 0;\n    ll cur =\
    \ a;\n    while ((tmp = gcd(tmp, m / g)) != 1) {\n        g *= tmp;\n        ++cnt;\n\
    \        (cur *= x) %= m;\n        if (cur == b) return cnt;\n    }\n    if (g\
    \ != 1) {\n        if (b % g != 0) return -1;\n        b /= g;\n        cur /=\
    \ g;\n        m /= g;\n    }\n\n    using mint = bmodint;\n    mint::set_mod(m);\n\
    \n    const ll ans = discrete_logarithm_mint<mint>(mint{cur}, mint{x}, mint{b});\n\
    \    if (ans == -1) return -1;\n    return ans + cnt;\n}\n\nll discrete_logarithm(ll\
    \ x, ll b, ll m) {\n    return discrete_logarithm(m == 1 ? 0 : 1, x, b, m);\n\
    }\n\n/**\n * @brief Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)\n * @docs docs/math/DiscreteLogarithm.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/DiscreteLogarithm.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/DiscreteLogarithm.hpp
layout: document
redirect_from:
- /library/math/DiscreteLogarithm.hpp
- /library/math/DiscreteLogarithm.hpp.html
title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
---
## 概要

$x, b, m$ が与えられたとき、 $x^k \equiv b \pmod m$ なる最小の非負整数 $k$ を求める。

- `ll baby_step_giant_step(T a, T b, U f, ll MAX)` : $f$ がたかだか $MAX$ の周期を持つとき、 $f^k(a)=b$ なる最小の非負整数 $k$ を返す。存在しない場合は $-1$ 。 $\Theta(\sqrt{MAX})$ 。
- `ll discrete_logarithm(ll a, ll x, ll b, ll m)` : $a \times x^k \equiv b \pmod m$ なる最小の非負整数 $k$ を返す。存在しない場合は $-1$ 。 $\Theta(\sqrt{m})$ 。
- `ll discrete_logarithm(ll x, ll b, ll m)` : $a=1$ の場合。離散対数。 $\Theta(\sqrt{m})$ 。
