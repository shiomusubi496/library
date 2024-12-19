---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/PrimitiveRoot.md
    document_title: "PrimitiveRoot(\u539F\u59CB\u6839)"
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
    \n#include \"ModInt.hpp\"\n#include \"MontgomeryModInt.hpp\"\n#include \"num/MillerRabin.hpp\"\
    \n#include \"num/PollardRho.hpp\"\n\ntemplate<class T = MontgomeryModInt<ull,\
    \ -4>> ull primitive_root(ull p) {\n    assert(is_prime_mr(p));\n    if (p ==\
    \ 2) return 1;\n    if (T::get_mod() != p) T::set_mod(p);\n    auto pf = factorize(p\
    \ - 1);\n    pf.erase(std::unique(all(pf)), pf.end());\n    for (auto&& x : pf)\
    \ x = (p - 1) / x;\n    T one = 1;\n    while (1) {\n        ull g = rand64.uniform(2ull,\
    \ p - 1);\n        bool ok = true;\n        for (const auto& x : pf) {\n     \
    \       if (T(g).pow(x) == one) {\n                ok = false;\n             \
    \   break;\n            }\n        }\n        if (ok) return g;\n    }\n}\n\n\
    /**\n * @brief PrimitiveRoot(\u539F\u59CB\u6839)\n * @docs docs/math/num/PrimitiveRoot.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/PrimitiveRoot.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/PrimitiveRoot.hpp
layout: document
redirect_from:
- /library/math/num/PrimitiveRoot.hpp
- /library/math/num/PrimitiveRoot.hpp.html
title: "PrimitiveRoot(\u539F\u59CB\u6839)"
---
## 概要

素数 $p$ に対し、 $\mod p$ における原始根、つまり $p-1$ 乗して始めて $1$ になる数を求める確率的アルゴリズム。

- `ull primitive_root(ull n)` : `n` の原始根を求める。 $O(\sqrt[4]{n})$ 。