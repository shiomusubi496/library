---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/tree/FrequencyTableofTreeDistance.md
    document_title: Frequency Table of Tree Distance
    links: []
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
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../../math/num/ChineseRemainder.hpp\"\
    \n#include \"../../math/ModInt.hpp\"\n#include \"../../math/convolution/Convolution.hpp\"\
    \n#include \"../Graph.hpp\"\n#include \"TreeCentroid.hpp\"\n\ntemplate<class T>\
    \ class FrequencyTableofTreeDistance {\nprivate:\n    static constexpr int MOD1\
    \ = 469762049;\n    static constexpr int MOD2 = 1811939329;\n    using mint1 =\
    \ static_modint<MOD1>;\n    using mint2 = static_modint<MOD2>;\n\n    int n;\n\
    \    const Graph<T>& G;\n    CentroidDecomposition<T> C;\n    std::vector<mint1>\
    \ ans1;\n    std::vector<mint2> ans2;\n    std::vector<ll> ans;\n\n    template<class\
    \ M> void build(std::vector<M>& ans) {\n        std::vector<int> st = {C.get_root()};\n\
    \        st.reserve(n);\n        std::vector<bool> seen(n, false);\n        std::vector<std::tuple<int,\
    \ int, int>> st2;\n        st2.reserve(n);\n        while (!st.empty()) {\n  \
    \          int v = st.back();\n            st.pop_back();\n            seen[v]\
    \ = true;\n            std::vector<std::vector<M>> dist;\n            dist.reserve(G[v].size());\n\
    \            for (const auto& s : G[v]) {\n                if (seen[s.to]) continue;\n\
    \                dist.push_back(std::vector<M>(2, 0));\n                st2.emplace_back(s.to,\
    \ -1, 1);\n                while (!st2.empty()) {\n                    int u,\
    \ p, d;\n                    std::tie(u, p, d) = st2.back();\n               \
    \     st2.pop_back();\n                    if ((int)dist.back().size() == d) dist.back().push_back(1);\n\
    \                    else ++dist.back()[d];\n                    for (const auto&\
    \ e : G[u]) {\n                        if (e.to == p || seen[e.to]) continue;\n\
    \                        st2.emplace_back(e.to, u, d + 1);\n                 \
    \   }\n                }\n            }\n            sort(all(dist),\n       \
    \          [](const std::vector<M>& a, const std::vector<M>& b) {\n          \
    \           return a.size() < b.size();\n                 });\n            std::vector<M>\
    \ tmp;\n            for (const auto& d : dist) {\n                if (tmp.empty())\
    \ {\n                    tmp = d;\n                    continue;\n           \
    \     }\n                auto tmp2 = convolution(tmp, d);\n                rep\
    \ (i, tmp2.size()) ans[i] += tmp2[i];\n                tmp.resize(d.size());\n\
    \                rep (i, d.size()) tmp[i] += d[i];\n            }\n          \
    \  rep (i, tmp.size()) ans[i] += tmp[i];\n            for (const auto& e : C.get()[v])\
    \ st.push_back(e.to);\n        }\n    }\n\npublic:\n    FrequencyTableofTreeDistance(const\
    \ Graph<T>& G_)\n        : n(G_.size()), G(G_), C(G_), ans1(n, 0), ans2(n, 0)\
    \ {\n        build(ans1);\n        build(ans2);\n        ans.resize(n);\n    \
    \    ans[0] = n;\n        rep (i, 1, n) {\n            ans[i] = ChineseRemainder(ans1[i].get(),\
    \ MOD1, ans2[i].get(), MOD2)\n                         .first;\n        }\n  \
    \  }\n    const std::vector<ll>& get() const& { return ans; }\n    std::vector<ll>\
    \ get() && { return std::move(ans); }\n};\n\n/**\n * @brief Frequency Table of\
    \ Tree Distance\n * @docs docs/graph/tree/FrequencyTableofTreeDistance.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/FrequencyTableofTreeDistance.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/FrequencyTableofTreeDistance.hpp
layout: document
redirect_from:
- /library/graph/tree/FrequencyTableofTreeDistance.hpp
- /library/graph/tree/FrequencyTableofTreeDistance.hpp.html
title: Frequency Table of Tree Distance
---
## 概要

木が与えられたとき、各 $d=0,1,\ldots,N-1$ について、 $\mathrm{dist}(u,v)=d$ なる頂点 $u, v$ $(u \leq v)$ の個数を求める。

重心分解をしたうえで畳み込みを用いているうえ、答えが N^2 オーダーになることから MOD を 2 つ用いているため、定数倍に注意が必要。

- `FrequencyTableofTreeDistance(Graph<T> G)` : 構築する。 $\Theta(N \log^2 N)$ 。
- `vector<ll> get()` : 答えを返す。 $\Theta(N)$ 。
