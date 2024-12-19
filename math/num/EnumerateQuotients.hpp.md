---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/EnumerateQuotients.md
    document_title: "Enumerate Quotients(\u5546\u5217\u6319)"
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
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n\nstd::vector<ll> enumerate_quotients(ll\
    \ n) {\n    std::vector<ll> res{1};\n    while (res.back() <= n) res.push_back(n\
    \ / (n / res.back()) + 1);\n    return res;\n}\n\n/**\n * @brief Enumerate Quotients(\u5546\
    \u5217\u6319)\n * @docs docs/math/num/EnumerateQuotients.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/EnumerateQuotients.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/EnumerateQuotients.hpp
layout: document
redirect_from:
- /library/math/num/EnumerateQuotients.hpp
- /library/math/num/EnumerateQuotients.hpp.html
title: "Enumerate Quotients(\u5546\u5217\u6319)"
---
## 概要

正整数 $n$ に対して、 $1 \leq i \leq n$ について $\lfloor \frac{n}{i} \rfloor$ の値はたかだか $2\lceil \sqrt{n} \rceil$ で抑えられる。これを列挙する。

- `vector<ll> enumerate_quotients(ll N)` : 返り値を $Q=(Q_1,Q_2,\ldots,Q_K)$ とすると、 $Q_1 = 1, Q_K = N+1$ で、 $\lfloor \frac{N}{Q_i} \rfloor = \lfloor \frac{N}{Q_{i+1}-1} \rfloor$ かつ $\lfloor \frac{N}{Q_i-1} \rfloor \neq \lfloor \frac{N}{Q_i} \rfloor$ を満たす。 $\{\lfloor \frac{N}{Q_i} \rfloor\}$ があり得る商の集合となる。 $\Theta(K)$ 。
