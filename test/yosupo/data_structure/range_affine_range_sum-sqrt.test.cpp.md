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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../../other/template.hpp\"\n#include \"../../../other/monoid2.hpp\"\
    \n#include \"../../../math/ModInt.hpp\"\n#include \"../../../data-struct/segment/SqrtDecomposition.hpp\"\
    \nusing namespace std;\nusing mint = modint998244353;\nusing PMM = pair<mint,\
    \ mint>;\nstruct CompositeAction {\n    using M = Monoid::Sum<mint>;\n    using\
    \ E = Monoid::Composite<mint>;\n    static mint op(const PMM& a, const mint& b)\
    \ {\n        return a.first * b + a.second;\n    }\n};\nint main() {\n    int\
    \ N, Q; scan >> N >> Q;\n    vector<mint> A(N); scan >> A;\n    auto f = [&](vector<mint>&&\
    \ v) -> pair<mint, int> {\n        mint ans = 0;\n        each_const (i : v) ans\
    \ += i;\n        return {ans, v.size()};\n    };\n    auto g = [&](const PMM&\
    \ x, pair<mint, int>& p) -> void {\n        p.first = p.first * x.first + p.second\
    \ * x.second;\n    };\n    SqrtDecomposition<mint, decltype(f), decltype(g), CompositeAction>\
    \ seg(A, f, g);\n    rep (Q) {\n        int t; scan >> t;\n        if (t == 0)\
    \ {\n            int l, r, b, c; scan >> l >> r >> b >> c;\n            seg.apply(l,\
    \ r, PMM{b, c});\n        }\n        else {\n            int l, r; scan >> l >>\
    \ r;\n            auto g = [&](const mint& x) -> mint {\n                return\
    \ x;\n            };\n            auto h = [&](const pair<mint, int>& p) -> mint\
    \ {\n                return p.first;\n            };\n            print << seg.prod<Monoid::Sum<mint>>(l,\
    \ r, g, h) << endl;\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp
- /verify/test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp.html
title: test/yosupo/data_structure/range_affine_range_sum-sqrt.test.cpp
---
