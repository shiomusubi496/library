---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/num/PrimeFactor.md
    document_title: "PrimeFactor(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
      )"
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
  code: "#pragma once\n\n#include \"../other/template.hpp\"\n\nclass PrimeFactor {\n\
    private:\n    int MAX;\n    std::vector<int> era, primes;\n\npublic:\n    PrimeFactor(int\
    \ MAX) : MAX(MAX), era(MAX + 1, -1), primes() {\n        rep (i, 2, MAX + 1) {\n\
    \            if (era[i] == -1) {\n                era[i] = i;\n              \
    \  primes.push_back(i);\n            }\n            for (const auto& p : primes)\
    \ {\n                if (i * p > MAX) break;\n                era[i * p] = p;\n\
    \            }\n        }\n    }\n    bool is_prime(int x) const { return era[x]\
    \ == x; }\n    int get_factor(int x) const { return era[x]; }\n    std::vector<int>\
    \ factorize(int x) const {\n        std::vector<int> res;\n        for (; x >\
    \ 1; x /= era[x]) res.push_back(era[x]);\n        return res;\n    }\n    const\
    \ std::vector<int>& get_primes() const& { return primes; }\n    std::vector<int>\
    \ get_primes() && { return std::move(primes); }\n};\n\nclass IsPrime {\nprivate:\n\
    \    int MAX;\n    std::vector<bool> era;\n    std::vector<int> primes;\n\npublic:\n\
    \    IsPrime(int MAX) : MAX(MAX), era(MAX + 1, true), primes() {\n        era[0]\
    \ = era[1] = false;\n        rep (i, 2, MAX + 1) {\n            if (era[i]) primes.push_back(i);\n\
    \            for (const auto& p : primes) {\n                if (i * p > MAX)\
    \ break;\n                era[i * p] = false;\n            }\n        }\n    }\n\
    \    bool is_prime(int x) { return era[x]; }\n    const std::vector<int>& get_primes()\
    \ const& { return primes; }\n    std::vector<int> get_primes() && { return std::move(primes);\
    \ }\n};\n\n/**\n * @brief PrimeFactor(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9)\n * @docs docs/math/num/PrimeFactor.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/num/PrimeFactor.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/num/PrimeFactor.hpp
layout: document
redirect_from:
- /library/math/num/PrimeFactor.hpp
- /library/math/num/PrimeFactor.hpp.html
title: "PrimeFactor(\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
---
## 概要

エラトステネスの篩を使った $\Theta(\log N)$ の素因数分解。ただし、前処理は $\Theta(N)$ 。

- `PrimeFactor(int N)` : `N` 以下の値に対してエラトステネスの篩のテーブルを作成する。$\Theta(N)$。
- `bool is_prime(int x)` : `x` が素数かどうか判定する。 $\Theta(1)$ 。
- `vector<int> factor(int x)` : `x` を素因数分解する。返る値は昇順。 $\Theta(\log N)$ 。
- `vector<int> get_primes(int x)` : `x` 以下の素数の列を返す。 $\Theta(x)$ 。

素数判定のみしたい場合は `IsPrime` を使う。オーダーは `PrimeFactor` と同様。
