---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/bitop.hpp
    title: template/bitop.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo_library_checker/data_structure/Static_Range_Sum.test.cpp
    title: verify/yosupo_library_checker/data_structure/Static_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Data_Structure/Disjoint_Sparse_Table.hpp\"\n\n#line 2 \"\
    template/bitop.hpp\"\n\n// \u975E\u8CA0\u6574\u6570 x \u306E bit legnth \u3092\
    \u6C42\u3081\u308B.\nll bit_length(ll x) {\n    if (x == 0) { return 0; }\n  \
    \  return (sizeof(long) * CHAR_BIT) - __builtin_clzll(x);\n}\n\n// \u975E\u8CA0\
    \u6574\u6570 x \u306E popcount \u3092\u6C42\u3081\u308B.\nll popcount(ll x) {\
    \ return __builtin_popcountll(x); }\n\n// \u6B63\u306E\u6574\u6570 x \u306B\u5BFE\
    \u3057\u3066, floor(log2(x)) \u3092\u6C42\u3081\u308B.\nll floor_log2(ll x) {\
    \ return bit_length(x) - 1; }\n\n// \u6B63\u306E\u6574\u6570 x \u306B\u5BFE\u3057\
    \u3066, ceil(log2(x)) \u3092\u6C42\u3081\u308B.\nll ceil_log2(ll x) { return bit_length(x\
    \ - 1); }\n\n// x \u306E\u7B2C k \u30D3\u30C3\u30C8\u3092\u53D6\u5F97\u3059\u308B\
    \nint get_bit(ll x, int k) { return (x >> k) & 1; }\n\n// x \u306E\u30D3\u30C3\
    \u30C8\u5217\u3092\u53D6\u5F97\u3059\u308B.\n// k \u306F\u30D3\u30C3\u30C8\u5217\
    \u306E\u9577\u3055\u3068\u3059\u308B.\nvector<int> get_bits(ll x, int k) {\n \
    \   vector<int> bits(k);\n    rep(i, k) {\n        bits[i] = x & 1;\n        x\
    \ >>= 1;\n    }\n\n    return bits;\n}\n\n// x \u306E\u30D3\u30C3\u30C8\u5217\u3092\
    \u53D6\u5F97\u3059\u308B.\nvector<int> get_bits(ll x) { return get_bits(x, bit_length(x));\
    \ }\n#line 4 \"Data_Structure/Disjoint_Sparse_Table.hpp\"\n\ntemplate<typename\
    \ M>\nclass Disjoint_Sparse_Table {\n    private:\n    int n, height;\n    std::vector<std::vector<M>>\
    \ table;\n    const std::function<M(M, M)> op;\n    const M unit;\n\n    public:\n\
    \    Disjoint_Sparse_Table(const std::vector<M> &data, const std::function<M(M,\
    \ M)> op, const M unit): n(data.size()), op(op), unit(unit), height(n > 0 ? ceil_log2(n)\
    \ : 0) {\n        table = std::vector<std::vector<M>>(height, std::vector<M>(n,\
    \ unit));\n\n        if (n == 0) { return; }\n\n        // \u521D\u6BB5\u306E\u521D\
    \u671F\u5316 \u2192 data \u914D\u5217\u3092\u305D\u306E\u307E\u307E\u30B3\u30D4\
    \u30FC\n\n        table[0] = data;\n\n        for (int h = 1; h < height; h++)\
    \ {\n            // h \u6BB5\u76EE\u306F, 2^h \u500B\u306E\u30D6\u30ED\u30C3\u30AF\
    \u304B\u3089\u306A\u308B.\n            int shift = 1 << h;\n\n            std::vector<M>\
    \ &row = table[h];\n\n            for (int j = 0; j < n; j += 2 * shift) {\n \
    \               // \u5DE6\u306B\u4F38\u3073\u308B\u7D2F\u7A4D\u7A4D\u3092\u6C42\
    \u3081\u308B.\n                int t = min(j + shift, n);\n                if\
    \ (t - 1 >= j) {\n                    row[t - 1] = data[t - 1];\n            \
    \        for (int k = t - 2; k >= j; k--) { row[k] = op(data[k], row[k + 1]);\
    \ }\n                }\n\n                if (n <= t) { break; }\n\n         \
    \       // \u53F3\u306B\u4F38\u3073\u308B\u7D2F\u7A4D\u7A4D\u3092\u6C42\u3081\u308B\
    .\n                row[t] = data[t];\n                int r = min(t + shift, n);\n\
    \                for (int k = t + 1; k < r; k++) { row[k] = op(row[k - 1], data[k]);\
    \ }\n            }\n        }\n    }\n\n    public:\n    M product(int l, int\
    \ r, bool left_close = true, bool right_close = true) const {\n        if (!left_close)\
    \ { l++; }\n        if (!right_close) { r--; }\n\n        if (l == r) { return\
    \ table[0][l]; }\n        if (l > r) { return unit; }\n\n        int h = bit_length(l\
    \ ^ r) - 1;\n        return op(table[h][l], table[h][r]);\n    }\n};\n"
  code: "#pragma once\n\n#include\"../template/bitop.hpp\"\n\ntemplate<typename M>\n\
    class Disjoint_Sparse_Table {\n    private:\n    int n, height;\n    std::vector<std::vector<M>>\
    \ table;\n    const std::function<M(M, M)> op;\n    const M unit;\n\n    public:\n\
    \    Disjoint_Sparse_Table(const std::vector<M> &data, const std::function<M(M,\
    \ M)> op, const M unit): n(data.size()), op(op), unit(unit), height(n > 0 ? ceil_log2(n)\
    \ : 0) {\n        table = std::vector<std::vector<M>>(height, std::vector<M>(n,\
    \ unit));\n\n        if (n == 0) { return; }\n\n        // \u521D\u6BB5\u306E\u521D\
    \u671F\u5316 \u2192 data \u914D\u5217\u3092\u305D\u306E\u307E\u307E\u30B3\u30D4\
    \u30FC\n\n        table[0] = data;\n\n        for (int h = 1; h < height; h++)\
    \ {\n            // h \u6BB5\u76EE\u306F, 2^h \u500B\u306E\u30D6\u30ED\u30C3\u30AF\
    \u304B\u3089\u306A\u308B.\n            int shift = 1 << h;\n\n            std::vector<M>\
    \ &row = table[h];\n\n            for (int j = 0; j < n; j += 2 * shift) {\n \
    \               // \u5DE6\u306B\u4F38\u3073\u308B\u7D2F\u7A4D\u7A4D\u3092\u6C42\
    \u3081\u308B.\n                int t = min(j + shift, n);\n                if\
    \ (t - 1 >= j) {\n                    row[t - 1] = data[t - 1];\n            \
    \        for (int k = t - 2; k >= j; k--) { row[k] = op(data[k], row[k + 1]);\
    \ }\n                }\n\n                if (n <= t) { break; }\n\n         \
    \       // \u53F3\u306B\u4F38\u3073\u308B\u7D2F\u7A4D\u7A4D\u3092\u6C42\u3081\u308B\
    .\n                row[t] = data[t];\n                int r = min(t + shift, n);\n\
    \                for (int k = t + 1; k < r; k++) { row[k] = op(row[k - 1], data[k]);\
    \ }\n            }\n        }\n    }\n\n    public:\n    M product(int l, int\
    \ r, bool left_close = true, bool right_close = true) const {\n        if (!left_close)\
    \ { l++; }\n        if (!right_close) { r--; }\n\n        if (l == r) { return\
    \ table[0][l]; }\n        if (l > r) { return unit; }\n\n        int h = bit_length(l\
    \ ^ r) - 1;\n        return op(table[h][l], table[h][r]);\n    }\n};\n"
  dependsOn:
  - template/bitop.hpp
  isVerificationFile: false
  path: Data_Structure/Disjoint_Sparse_Table.hpp
  requiredBy: []
  timestamp: '2026-02-14 19:18:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo_library_checker/data_structure/Static_Range_Sum.test.cpp
documentation_of: Data_Structure/Disjoint_Sparse_Table.hpp
layout: document
title: Disjoint Sparse Table
---

## Outline

Monoid $M$ の静的な列 $S = (S_0, S_1, \dots, S_{N-1})$ に対する区間積を以下の高速な計算量で計算を行う.

* 前計算: $O(N \log N)$ 時間.
* 本計算: $O(1)$ 時間.

## Contents

### Constructer

```cpp
Disjoint_Sparse_Table D(const std::vector<M> &data, const std::function<M(M, M)> op, const M unit)
```

* Monoid $M$ 上の静的な列 `data` に関する Disjoint Sparse Table を構築する.
* **引数**
  * `data`: $M$ 上の列
  * `op`: $M$ における演算 $M \times M \to M; (x, y) \mapsto xy$.
  * `unit`: $M$ における単位元.
* **計算量**:
  * `data` のサイズを $N$ として, $O(N \log N)$ 時間.

### product

```cpp
M S.product(int l, int r, bool left_close = true, bool right_close = true)
```

* 区間積 $S_l * S_{l+1} * \dots * S_r$ を求める.
* **引数**
  * `left_close`: `false` にすると, 左端が開区間になる.
  * `right_close`: `false` にすると, 右端が開区間になる.
* **制約**
  * 積を取る区間が $[0, N)$ に含まれる.
* **計算量** : $O(1)$ 時間
