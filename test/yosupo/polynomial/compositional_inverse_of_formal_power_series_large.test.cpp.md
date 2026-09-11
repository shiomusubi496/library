---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.16/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../math/poly/CompositionalInverse.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../math/poly/FormalPowerSeries.hpp\"\
    \n#include \"../../../math/poly/CompositionalInverse.hpp\"\n#include \"../../../math/ModInt.hpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nint main() {\n    int n;\
    \ scan >> n;\n    FormalPowerSeries<mint> f(n); scan >> f;\n    prints(compositional_inverse(f));\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/polynomial/compositional_inverse_of_formal_power_series_large.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/polynomial/compositional_inverse_of_formal_power_series_large.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/polynomial/compositional_inverse_of_formal_power_series_large.test.cpp
- /verify/test/yosupo/polynomial/compositional_inverse_of_formal_power_series_large.test.cpp.html
title: test/yosupo/polynomial/compositional_inverse_of_formal_power_series_large.test.cpp
---
