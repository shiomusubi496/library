---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data-struct/sequence/SlidingWindowAggregation.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include \"../../other/template.hpp\"\n#include \"../../other/monoid2.hpp\"\n\
    #include \"../../math/ModInt.hpp\"\n#include \"../../data-struct/sequence/SlidingWindowAggregation.hpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nint main() {\n    int Q;\
    \ cin >> Q;\n    SlidingWindowAggregation<Monoid::Composite<mint>> SWAG;\n   \
    \ rep (Q) {\n        int t; cin >> t;\n        if (t == 0) {\n            mint\
    \ a, b; cin >> a >> b;\n            SWAG.emplace(a, b);\n        }\n        else\
    \ if (t == 1) SWAG.pop();\n        else {\n            mint x; cin >> x;\n   \
    \         auto p = SWAG.all_prod();\n            cout << p.first * x + p.second\
    \ << endl;\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---
