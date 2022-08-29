---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../other/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"../../../other/template.hpp\"\n#include \"../../../other/monoid.hpp\"\
    \n#include \"../../../data-struct/segment/SqrtDecomposition.hpp\"\nusing namespace\
    \ std;\nint main() {\n    int N, Q; scan >> N >> Q;\n    vector<int> A(N); scan\
    \ >> A;\n    presser<int> ps(A); ps.build();\n    ps.press(A);\n    auto f = [&](vector<int>&&\
    \ v) -> vector<int> {\n        vector<int> A(ps.size());\n        each_const (i\
    \ : v) ++A[i];\n        rep (i, ps.size() - 1) A[i + 1] += A[i];\n        return\
    \ A;\n    };\n    SqrtDecomposition<int, decltype(f)> sd(A, f);\n    rep (Q) {\n\
    \        int l, r, k; scan >> l >> r >> k;\n        int ok = ps.size() - 1, ng\
    \ = -1;\n        while (ok - ng > 1) {\n            int mid = (ok + ng) / 2;\n\
    \            auto g = [&](int x) -> int {\n                return x <= mid;\n\
    \            };\n            auto h = [&](const vector<int>& v) -> int {\n   \
    \             return v[mid];\n            };\n            int cnt = sd.prod<Monoid::Sum<int>>(l,\
    \ r, g, h);\n            if (cnt > k) ok = mid;\n            else ng = mid;\n\
    \        }\n        print << ps[ok] << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/data_structure/range_kth_smallest-sqrt.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_structure/range_kth_smallest-sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/range_kth_smallest-sqrt.test.cpp
- /verify/test/yosupo/data_structure/range_kth_smallest-sqrt.test.cpp.html
title: test/yosupo/data_structure/range_kth_smallest-sqrt.test.cpp
---
