---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../graph/tree/Tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n#include\
    \ \"../../../other/template.hpp\"\n#include \"../../../graph/Graph.hpp\"\n#include\
    \ \"../../../graph/tree/Tree.hpp\"\nusing namespace std;\nint main() {\n    int\
    \ N; cin >> N;\n    Graph<int> G(N);\n    rep (i, N) {\n        int k; cin >>\
    \ k;\n        rep (k) {\n            int t; cin >> t;\n            G.add_edge(i,\
    \ t, true);\n        }\n    }\n    Tree<int> T(G);\n    int Q; cin >> Q;\n   \
    \ rep (i, Q) {\n        int a, b; cin >> a >> b;\n        cout << T.lca(a, b)\
    \ << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/GRL/GRL_5_C-LCA.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_5_C-LCA.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_5_C-LCA.test.cpp
- /verify/test/aoj/GRL/GRL_5_C-LCA.test.cpp.html
title: test/aoj/GRL/GRL_5_C-LCA.test.cpp
---
