---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_square_sum\"\n#include\
    \ \"../../../other/template.hpp\"\n#include \"../../../math/num/TwoSquareSum.hpp\"\
    \nusing namespace std;\nint main() {\n    int T; scan >> T;\n    rep (T) {\n \
    \       ll n; scan >> n;\n        if (n == 0) {\n            prints(1);\n    \
    \        prints(0, 0);\n            continue;\n        }\n        auto res = two_square_sum(n);\n\
    \        vector<pair<ll, ll>> ans;\n        for (auto [a, b] : res) {\n      \
    \      rep (4) {\n                swap(a, b);\n                a = -a;\n     \
    \           if (a >= 0 && b >= 0) ans.emplace_back(a, b);\n            }\n   \
    \     }\n        prints(ans.size());\n        for (auto p : ans) prints(p);\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/new/two_square_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/new/two_square_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/new/two_square_sum.test.cpp
- /verify/test/yosupo/new/two_square_sum.test.cpp.html
title: test/yosupo/new/two_square_sum.test.cpp
---
