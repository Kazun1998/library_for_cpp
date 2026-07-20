---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Heuristic/Simulated_Annealing.hpp
    title: Heuristic/Simulated_Annealing.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30BF\u30A4\u30DE\u30FC\u306E\u7D4C\u904E\u6642\u9593\u3092\
      \ 0 \u306B\u3059\u308B."
    links: []
  bundledCode: "#line 2 \"Heuristic/Timer.hpp\"\n#include <chrono>\n#include <algorithm>\n\
    \nclass Timer {\n    private:\n    std::chrono::steady_clock::time_point start_time;\n\
    \    double time_limit; // \u79D2\u5358\u4F4D\n\n    public:\n    Timer(double\
    \ limit_sec) : time_limit(limit_sec) {\n        reset();\n    }\n\n    /// @brief\
    \ \u30BF\u30A4\u30DE\u30FC\u306E\u7D4C\u904E\u6642\u9593\u3092 0 \u306B\u3059\u308B\
    .\n    void reset() {\n        start_time = std::chrono::steady_clock::now();\n\
    \    }\n\n    /// @brief \u7D4C\u904E\u6642\u9593 (s) \u3092\u6C42\u3081\u308B\
    .\n    /// @return \u7D4C\u904E\u6642\u9593 (s)\n    double elapsed() const {\n\
    \        auto now = std::chrono::steady_clock::now();\n        return std::chrono::duration<double>(now\
    \ - start_time).count();\n    }\n\n    /// @brief \u5236\u9650\u6642\u9593\u307E\
    \u3067\u306E\u3046\u3061\u306E\u9032\u884C\u6642\u9593\u306E\u5272\u5408\u3092\
    \ 0.0 ~ 1.0 \u3067\u6C42\u3081\u308B\n    /// @return \u5236\u9650\u6642\u9593\
    \u307E\u3067\u306E\u3046\u3061\u306E\u9032\u884C\u6642\u9593\u306E\u5272\u5408\
    \n    double progress() const {\n        return std::min(1.0, elapsed() / time_limit);\n\
    \    }\n\n    /// @brief \u7D42\u4E86\u5224\u5B9A\n    /// @param margin_sec \u7D42\
    \u4E86\u5224\u5B9A\u306B\u4F59\u88D5\u3092\u6301\u305F\u305B\u308B\u305F\u3081\
    \u306E\u30DE\u30FC\u30B8\u30F3 (s)\n    /// @return \u7D42\u4E86\u3059\u3079\u304D\
    \u306A\u3089\u3070 true.\n    bool is_time_up(double margin_sec = 0.005) const\
    \ {\n        return elapsed() > (time_limit - margin_sec);\n    }\n};\n"
  code: "#pragma once\n#include <chrono>\n#include <algorithm>\n\nclass Timer {\n\
    \    private:\n    std::chrono::steady_clock::time_point start_time;\n    double\
    \ time_limit; // \u79D2\u5358\u4F4D\n\n    public:\n    Timer(double limit_sec)\
    \ : time_limit(limit_sec) {\n        reset();\n    }\n\n    /// @brief \u30BF\u30A4\
    \u30DE\u30FC\u306E\u7D4C\u904E\u6642\u9593\u3092 0 \u306B\u3059\u308B.\n    void\
    \ reset() {\n        start_time = std::chrono::steady_clock::now();\n    }\n\n\
    \    /// @brief \u7D4C\u904E\u6642\u9593 (s) \u3092\u6C42\u3081\u308B.\n    ///\
    \ @return \u7D4C\u904E\u6642\u9593 (s)\n    double elapsed() const {\n       \
    \ auto now = std::chrono::steady_clock::now();\n        return std::chrono::duration<double>(now\
    \ - start_time).count();\n    }\n\n    /// @brief \u5236\u9650\u6642\u9593\u307E\
    \u3067\u306E\u3046\u3061\u306E\u9032\u884C\u6642\u9593\u306E\u5272\u5408\u3092\
    \ 0.0 ~ 1.0 \u3067\u6C42\u3081\u308B\n    /// @return \u5236\u9650\u6642\u9593\
    \u307E\u3067\u306E\u3046\u3061\u306E\u9032\u884C\u6642\u9593\u306E\u5272\u5408\
    \n    double progress() const {\n        return std::min(1.0, elapsed() / time_limit);\n\
    \    }\n\n    /// @brief \u7D42\u4E86\u5224\u5B9A\n    /// @param margin_sec \u7D42\
    \u4E86\u5224\u5B9A\u306B\u4F59\u88D5\u3092\u6301\u305F\u305B\u308B\u305F\u3081\
    \u306E\u30DE\u30FC\u30B8\u30F3 (s)\n    /// @return \u7D42\u4E86\u3059\u3079\u304D\
    \u306A\u3089\u3070 true.\n    bool is_time_up(double margin_sec = 0.005) const\
    \ {\n        return elapsed() > (time_limit - margin_sec);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Heuristic/Timer.hpp
  requiredBy:
  - Heuristic/Simulated_Annealing.hpp
  timestamp: '2026-07-21 00:54:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Heuristic/Timer.hpp
layout: document
redirect_from:
- /library/Heuristic/Timer.hpp
- /library/Heuristic/Timer.hpp.html
title: "\u30BF\u30A4\u30DE\u30FC\u306E\u7D4C\u904E\u6642\u9593\u3092 0 \u306B\u3059\
  \u308B."
---
