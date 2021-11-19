---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n#include\
    \ \"../../../template.hpp\"\n#include \"../../../data-struct/segment/BinaryIndexedTree.hpp\"\
    \nusing namespace std;\nint main() {\n    int n, q; cin >> n >> q;\n    BinaryIndexedTree<int>\
    \ BIT(n);\n    rep (q) {\n        int t, a, b; cin >> t >> a >> b;\n        if\
    \ (t == 0) BIT.add(a - 1, b);\n        else cout << BIT.sum(a - 1, b) << endl;\n\
    \    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/DLS/DSL_2_B-BIT.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DLS/DSL_2_B-BIT.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DLS/DSL_2_B-BIT.test.cpp
- /verify/test/aoj/DLS/DSL_2_B-BIT.test.cpp.html
title: test/aoj/DLS/DSL_2_B-BIT.test.cpp
---
