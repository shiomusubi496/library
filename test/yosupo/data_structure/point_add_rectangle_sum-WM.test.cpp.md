---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../data-struct/wavelet/WaveletMatrixPointAddRectangleSum.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../other/monoid.hpp\"\
    \n#include \"../../../data-struct/wavelet/WaveletMatrixPointAddRectangleSum.hpp\"\
    \nusing namespace std;\nint main() {\n    int N, Q; scan >> N >> Q;\n    vector<array<ll,\
    \ 3>> A(N); scan >> A;\n    vector<array<ll, 5>> B(Q);\n    each_for ([a, b, c,\
    \ d, e] : B) {\n        scan >> a;\n        if (a == 0) scan >> b >> c >> d;\n\
    \        else scan >> b >> c >> d >> e;\n    }\n    WaveletMatrixPointAddRectangleSum<ll,\
    \ Monoid::Sum<ll>> wm;\n    rep (i, N) wm.add_point(A[i][0], A[i][1]);\n    rep\
    \ (i, Q) {\n        if (B[i][0] == 0) wm.add_point(B[i][1], B[i][2]);\n    }\n\
    \    wm.build();\n    rep (i, N) wm.apply(A[i][0], A[i][1], A[i][2]);\n    each_const\
    \ ([a, b, c, d, e] : B) {\n        if (a == 0) wm.apply(b, c, d);\n        else\
    \ print << wm.prod(b, d, c, e) << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/data_structure/point_add_rectangle_sum-WM.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_structure/point_add_rectangle_sum-WM.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/point_add_rectangle_sum-WM.test.cpp
- /verify/test/yosupo/data_structure/point_add_rectangle_sum-WM.test.cpp.html
title: test/yosupo/data_structure/point_add_rectangle_sum-WM.test.cpp
---
