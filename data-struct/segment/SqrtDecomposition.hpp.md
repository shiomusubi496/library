---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-struct/segment/SqrtDecomposition.md
    document_title: "SqrtDecomposition(\u5E73\u65B9\u5206\u5272)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../other/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../../other/template.hpp\"\n#include \"../../other/monoid.hpp\"\
    \n#include \"../../other/type_traits.hpp\"\n\ntemplate<class T, class F, class\
    \ G = void, class A = void>\nclass SqrtDecomposition;\n\ntemplate<class T, class\
    \ F> class SqrtDecomposition<T, F, void, void> {\n    static_assert(std::is_same<typename\
    \ function_traits<F>::argument_tuple,\n                               std::tuple<std::vector<T>&&>>::value,\n\
    \                  \"F must take a single argument of type vector<T>&&\");\n\n\
    protected:\n    using U = typename function_traits<F>::result_type;\n    int n,\
    \ b, nb;\n    F f;\n    std::vector<T> v;\n    std::vector<U> data;\n    virtual\
    \ void eval(int) { return; }\n\npublic:\n    SqrtDecomposition(const std::vector<T>&\
    \ v_, const F& f) : f(f) { init(v_); }\n    SqrtDecomposition(const std::vector<T>&\
    \ v_, int b_, const F& f) : f(f) {\n        init(v_, b_);\n    }\n    void init(const\
    \ std::vector<T>& v_, int b_ = -1) {\n        v = v_;\n        n = v.size();\n\
    \        if (b_ == -1) b_ = sqrt(n);\n        b = b_;\n        nb = n / b;\n \
    \       data.reserve(nb);\n        rep (i, nb) {\n            std::vector<T> v2(v.begin()\
    \ + i * b, v.begin() + (i + 1) * b);\n            data.push_back(f(std::move(v2)));\n\
    \        }\n    }\n    template<class M, class G, class H>\n    auto prod(int\
    \ l, int r, const G& g, const H& h) -> typename std::enable_if<\n        Monoid::is_monoid<M>::value\
    \ &&\n            std::is_same<decltype(g(std::declval<T>())),\n             \
    \            typename M::value_type>::value &&\n            std::is_same<decltype(h(std::declval<U>())),\n\
    \                         typename M::value_type>::value,\n        typename M::value_type>::type\
    \ {\n        using S = typename M::value_type;\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        const int lb = l / b, rb = r / b;\n        if (lb ==\
    \ rb) {\n            if (lb < nb) eval(lb);\n            S res = M::id();\n  \
    \          rep (i, l, r) res = M::op(res, g(v[i]));\n            return res;\n\
    \        }\n        eval(lb);\n        if (rb < nb) eval(rb);\n        S res =\
    \ M::id();\n        rep (i, l, b * (lb + 1)) res = M::op(res, g(v[i]));\n    \
    \    rep (i, lb + 1, rb) res = M::op(res, h(data[i]));\n        rep (i, rb * b,\
    \ r) res = M::op(res, g(v[i]));\n        return res;\n    }\n    template<class\
    \ G>\n    auto update(int k, const G& g) -> typename std::enable_if<\n       \
    \ std::is_same<decltype(g(std::declval<T&>())), void>::value>::type {\n      \
    \  assert(0 <= k && k < n);\n        const int bk = k / b;\n        if (bk < nb)\
    \ eval(bk);\n        g(v[k]);\n        if (bk < nb) {\n            std::vector<T>\
    \ v2(v.begin() + bk * b, v.begin() + (bk + 1) * b);\n            data[bk] = f(std::move(v2));\n\
    \        }\n    }\n    void set(int k, const T& x) {\n        update(k, [&](T&\
    \ y) -> void { y = x; });\n    }\n};\n\ntemplate<class T, class F, class G, class\
    \ A>\nclass SqrtDecomposition : public SqrtDecomposition<T, F, void> {\nprivate:\n\
    \    using Base = SqrtDecomposition<T, F, void>;\n    using E = typename A::E;\n\
    \    using U = typename Base::U;\n    using S = typename E::value_type;\n\n  \
    \  static_assert(std::is_same<typename A::M::value_type, T>::value,\n        \
    \          \"A::M::value_type and T must be same\");\n\n    G g;\n    std::vector<S>\
    \ lazy;\n    std::vector<bool> lazyflag;\n    void eval(int i) override {\n  \
    \      if (lazyflag[i]) {\n            rep (j, this->b)\n                this->v[i\
    \ * this->b + j] =\n                    A::op(lazy[i], this->v[i * this->b + j]);\n\
    \            lazyflag[i] = false;\n        }\n    }\n    void all_apply(const\
    \ S& x, int i) {\n        g(x, this->data[i]);\n        if (lazyflag[i]) {\n \
    \           lazy[i] = E::op(lazy[i], x);\n        }\n        else {\n        \
    \    lazy[i] = x;\n            lazyflag[i] = true;\n        }\n    }\n\npublic:\n\
    \    SqrtDecomposition(const std::vector<T>& v_, const F& f, const G& g)\n   \
    \     : Base(v_, f), g(g), lazy(this->nb), lazyflag(this->nb, false) {}\n    SqrtDecomposition(const\
    \ std::vector<T>& v_, int b_, const F& f, const G& g)\n        : Base(v_, b_,\
    \ f), g(g), lazy(this->nb), lazyflag(this->nb, false) {}\n    void apply(int k,\
    \ const S& x) {\n        this->update(k, [&](T& y) -> void { y = A::op(x, y);\
    \ });\n    }\n    auto apply(int l, int r, const S& x) -> typename std::enable_if<\n\
    \        std::is_same<decltype(g(x, std::declval<U&>())), void>::value>::type\
    \ {\n        assert(0 <= l && l <= r && r <= this->n);\n        const int lb =\
    \ l / this->b, rb = r / this->b;\n        if (lb == rb) {\n            if (lb\
    \ < this->nb) eval(lb);\n            rep (i, l, r) this->v[i] = A::op(x, this->v[i]);\n\
    \            if (lb < this->nb) {\n                std::vector<T> v2(this->v.begin()\
    \ + lb * this->b,\n                                  this->v.begin() + (lb + 1)\
    \ * this->b);\n                this->data[lb] = this->f(std::move(v2));\n    \
    \        }\n            return;\n        }\n        eval(lb);\n        if (rb\
    \ < this->nb) eval(rb);\n        rep (i, l, this->b * (lb + 1)) this->v[i] = A::op(x,\
    \ this->v[i]);\n        rep (i, lb + 1, rb) all_apply(x, i);\n        rep (i,\
    \ rb * this->b, r) this->v[i] = A::op(x, this->v[i]);\n        {\n           \
    \ std::vector<T> v2(this->v.begin() + lb * this->b,\n                        \
    \      this->v.begin() + (lb + 1) * this->b);\n            this->data[lb] = this->f(std::move(v2));\n\
    \        }\n        if (rb < this->nb) {\n            std::vector<T> v2(this->v.begin()\
    \ + rb * this->b,\n                              this->v.begin() + (rb + 1) *\
    \ this->b);\n            this->data[rb] = this->f(std::move(v2));\n        }\n\
    \    }\n};\n\n/**\n * @brief SqrtDecomposition(\u5E73\u65B9\u5206\u5272)\n * @docs\
    \ docs/data-struct/segment/SqrtDecomposition.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: data-struct/segment/SqrtDecomposition.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-struct/segment/SqrtDecomposition.hpp
layout: document
redirect_from:
- /library/data-struct/segment/SqrtDecomposition.hpp
- /library/data-struct/segment/SqrtDecomposition.hpp.html
title: "SqrtDecomposition(\u5E73\u65B9\u5206\u5272)"
---
## 概要

いわゆるバケット法の平方分割。

- `SqrtDecomposition(vector<T> a, F f)` : 列 `a` と各バケットに持たせるデータを返す `f(vector<T>)` で初期化。バケットサイズは $\sqrt{n}$ 。 $\Theta(n)$ 。
- `SqrtDecomposition(vector<T> a, int b, F f)` : バケットの大きさ `b` を指定して初期化。 $\Theta(n)$ 。
- `S prod(int l, int r, G g, H h)` : `T` から値を得る `S g(T)` 、各バケットのデータから値を得る `S h(U)` を使って `M::op(a[l], a[l+1], ..., a[r-1])` を返す。
- `void apply(int l, int r, G g, H h)` : `T` を変更する `void g(T&)` 、各バケットのデータを更新する `void h(U&)` を使って `M::op(a[l], a[l+1], ..., a[r-1])` を返す。
