---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/KthRoot.md
    document_title: "KthRoot(k\u4E57\u6839)"
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
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n\null kth_root(ull n,\
    \ ull k) {\n    if (n <= 1 || k == 1) return n;\n    if (k >= 65) return 1;\n\
    \    auto is_over = [&](ull x) -> bool {\n        u128 res = 1, a = x;\n     \
    \   for (int b = k; b; b >>= 1, a *= a) {\n            if (b & 1) res *= a;\n\
    \        }\n        return res > n;\n    };\n    ll res = pow(n, 1.0 / k);\n \
    \   while (!is_over(res + 1)) ++res;\n    while (is_over(res)) --res;\n    return\
    \ res;\n}\n\n/**\n * @brief KthRoot(k\u4E57\u6839)\n * @docs docs/math/num/KthRoot.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/KthRoot.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/KthRoot.hpp
layout: document
redirect_from:
- /library/math/num/KthRoot.hpp
- /library/math/num/KthRoot.hpp.html
title: "KthRoot(k\u4E57\u6839)"
---
## 概要

非負整数 `n` と正整数 `k` に対して、 $\lfloor \sqrt[k]{n} \rfloor$ を求める。 `std::sqrt` を使っている。
