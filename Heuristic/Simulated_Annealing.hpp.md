---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Heuristic/Random.hpp
    title: Heuristic/Random.hpp
  - icon: ':warning:'
    path: Heuristic/Timer.hpp
    title: "\u30BF\u30A4\u30DE\u30FC\u306E\u7D4C\u904E\u6642\u9593\u3092 0 \u306B\u3059\
      \u308B."
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Heuristic/Simulated_Annealing.hpp\"\n#include <cmath>\n\
    #line 2 \"Heuristic/Timer.hpp\"\n#include <chrono>\n#include <algorithm>\n\nclass\
    \ Timer {\n    private:\n    std::chrono::steady_clock::time_point start_time;\n\
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
    \ {\n        return elapsed() > (time_limit - margin_sec);\n    }\n};\n#line 2\
    \ \"Heuristic/Random.hpp\"\n#include <random>\n\n// \u7AF6\u6280\u30D7\u30ED\u30B0\
    \u30E9\u30DF\u30F3\u30B0\uFF08\u30DE\u30E9\u30BD\u30F3\u30DE\u30C3\u30C1\uFF09\
    \u7528\u306E\u4E71\u6570\u751F\u6210\u30AF\u30E9\u30B9\nclass Random {\npublic:\n\
    \    // \u30B7\u30FC\u30C9\u3092\u6307\u5B9A\u3057\u3066\u521D\u671F\u5316\uFF08\
    \u30C7\u30D5\u30A9\u30EB\u30C8\u306F\u56FA\u5B9A\u5024\u3067\u518D\u73FE\u6027\
    \u3092\u62C5\u4FDD\uFF09\n    explicit Random(uint32_t seed = 42) : engine(seed)\
    \ {}\n\n    // [min_val, max_val] \u306E\u7BC4\u56F2\u306E\u6574\u6570\u3092\u30E9\
    \u30F3\u30C0\u30E0\u306B\u751F\u6210\u3059\u308B\uFF08\u4E21\u7AEF\u542B\u3080\
    \uFF09\n    // @param min_val \u6700\u5C0F\u5024\n    // @param max_val \u6700\
    \u5927\u5024\n    // @return \u751F\u6210\u3055\u308C\u305F\u4E71\u6570\n    int\
    \ next_int(int min_val, int max_val) {\n        std::uniform_int_distribution<int>\
    \ dist(min_val, max_val);\n        return dist(engine);\n    }\n\n    // [0.0,\
    \ 1.0) \u306E\u7BC4\u56F2\u306E\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u3092\u30E9\
    \u30F3\u30C0\u30E0\u306B\u751F\u6210\u3059\u308B\n    // @return \u751F\u6210\u3055\
    \u308C\u305F\u4E71\u6570\n    double next_double() {\n        std::uniform_real_distribution<double>\
    \ dist(0.0, 1.0);\n        return dist(engine);\n    }\n\n    // [min_val, max_val)\
    \ \u306E\u7BC4\u56F2\u306E\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u3092\u30E9\u30F3\
    \u30C0\u30E0\u306B\u751F\u6210\u3059\u308B\n    // @param min_val \u6700\u5C0F\
    \u5024\n    // @param max_val \u6700\u5927\u5024\n    // @return \u751F\u6210\u3055\
    \u308C\u305F\u4E71\u6570\n    double next_double(double min_val, double max_val)\
    \ {\n        std::uniform_real_distribution<double> dist(min_val, max_val);\n\
    \        return dist(engine);\n    }\n\nprivate:\n    std::mt19937 engine;\n};\n\
    #line 5 \"Heuristic/Simulated_Annealing.hpp\"\n\n// \u713C\u304D\u306A\u307E\u3057\
    \u6CD5 (Simulated Annealing) \u306E\u9077\u79FB\u5236\u5FA1\u30FB\u72B6\u614B\u7BA1\
    \u7406\u3092\u53F8\u308B\u30AF\u30E9\u30B9\nclass Simulated_Annealing {\npublic:\n\
    \    // \u6E29\u5EA6\u306E\u6E1B\u8870\u30B9\u30B1\u30B8\u30E5\u30FC\u30EB\n \
    \   enum class Schedule { Linear, Exponential };\n\n    // @param t_start \u958B\
    \u59CB\u6E29\u5EA6\n    // @param t_end \u7D42\u4E86\u6E29\u5EA6\n    // @param\
    \ timer \u30BF\u30A4\u30DE\u30FC\uFF08\u30B3\u30D4\u30FC\u3057\u3066\u4FDD\u6301\
    \u3059\u308B\uFF09\n    // @param schedule \u6E29\u5EA6\u306E\u6E1B\u8870\u30B9\
    \u30B1\u30B8\u30E5\u30FC\u30EB\uFF08\u65E2\u5B9A\u306F\u7DDA\u5F62\uFF09\n   \
    \ Simulated_Annealing(double t_start, double t_end, Timer timer, Schedule schedule\
    \ = Schedule::Linear)\n        : t_start(t_start), t_end(t_end), timer(timer),\
    \ schedule(schedule) {}\n\n    // \u73FE\u5728\u306E\u6E29\u5EA6\u3092\u53D6\u5F97\
    \u3059\u308B\n    // @return \u73FE\u5728\u306E\u6E29\u5EA6\n    double get_temp()\
    \ const {\n        double progress = timer.progress();\n        if (schedule ==\
    \ Schedule::Exponential) {\n            return t_start * std::pow(t_end / t_start,\
    \ progress);\n        }\n        return t_start + (t_end - t_start) * progress;\n\
    \    }\n\n    // \u9077\u79FB\u3092\u53D7\u3051\u5165\u308C\u308B\u304B\u3069\u3046\
    \u304B\u5224\u5B9A\u3059\u308B (Metropolis Criterion)\n    // @param score_diff\
    \ \u30B9\u30B3\u30A2\u306E\u5909\u5316\u91CF (new_score - old_score)\n    // @param\
    \ rnd \u4E71\u6570\u751F\u6210\u5668\u306E\u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\
    \n    // @return \u53D7\u3051\u5165\u308C\u308B\u306A\u3089 true, \u305D\u3046\
    \u3067\u306A\u3051\u308C\u3070 false\n    bool accept(double score_diff, Random&\
    \ rnd) const {\n        if (score_diff >= 0.0) {\n            return true;\n \
    \       }\n        double temp = get_temp();\n        if (temp <= 1e-9) return\
    \ false;\n\n        double prob = std::exp(score_diff / temp);\n        return\
    \ rnd.next_double() < prob;\n    }\n\n    private:\n    double t_start;\n    double\
    \ t_end;\n    Timer timer;\n    Schedule schedule;\n};\n"
  code: "#pragma once\n#include <cmath>\n#include \"Timer.hpp\"\n#include \"Random.hpp\"\
    \n\n// \u713C\u304D\u306A\u307E\u3057\u6CD5 (Simulated Annealing) \u306E\u9077\
    \u79FB\u5236\u5FA1\u30FB\u72B6\u614B\u7BA1\u7406\u3092\u53F8\u308B\u30AF\u30E9\
    \u30B9\nclass Simulated_Annealing {\npublic:\n    // \u6E29\u5EA6\u306E\u6E1B\u8870\
    \u30B9\u30B1\u30B8\u30E5\u30FC\u30EB\n    enum class Schedule { Linear, Exponential\
    \ };\n\n    // @param t_start \u958B\u59CB\u6E29\u5EA6\n    // @param t_end \u7D42\
    \u4E86\u6E29\u5EA6\n    // @param timer \u30BF\u30A4\u30DE\u30FC\uFF08\u30B3\u30D4\
    \u30FC\u3057\u3066\u4FDD\u6301\u3059\u308B\uFF09\n    // @param schedule \u6E29\
    \u5EA6\u306E\u6E1B\u8870\u30B9\u30B1\u30B8\u30E5\u30FC\u30EB\uFF08\u65E2\u5B9A\
    \u306F\u7DDA\u5F62\uFF09\n    Simulated_Annealing(double t_start, double t_end,\
    \ Timer timer, Schedule schedule = Schedule::Linear)\n        : t_start(t_start),\
    \ t_end(t_end), timer(timer), schedule(schedule) {}\n\n    // \u73FE\u5728\u306E\
    \u6E29\u5EA6\u3092\u53D6\u5F97\u3059\u308B\n    // @return \u73FE\u5728\u306E\u6E29\
    \u5EA6\n    double get_temp() const {\n        double progress = timer.progress();\n\
    \        if (schedule == Schedule::Exponential) {\n            return t_start\
    \ * std::pow(t_end / t_start, progress);\n        }\n        return t_start +\
    \ (t_end - t_start) * progress;\n    }\n\n    // \u9077\u79FB\u3092\u53D7\u3051\
    \u5165\u308C\u308B\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B (Metropolis\
    \ Criterion)\n    // @param score_diff \u30B9\u30B3\u30A2\u306E\u5909\u5316\u91CF\
    \ (new_score - old_score)\n    // @param rnd \u4E71\u6570\u751F\u6210\u5668\u306E\
    \u30A4\u30F3\u30B9\u30BF\u30F3\u30B9\n    // @return \u53D7\u3051\u5165\u308C\u308B\
    \u306A\u3089 true, \u305D\u3046\u3067\u306A\u3051\u308C\u3070 false\n    bool\
    \ accept(double score_diff, Random& rnd) const {\n        if (score_diff >= 0.0)\
    \ {\n            return true;\n        }\n        double temp = get_temp();\n\
    \        if (temp <= 1e-9) return false;\n\n        double prob = std::exp(score_diff\
    \ / temp);\n        return rnd.next_double() < prob;\n    }\n\n    private:\n\
    \    double t_start;\n    double t_end;\n    Timer timer;\n    Schedule schedule;\n\
    };\n"
  dependsOn:
  - Heuristic/Timer.hpp
  - Heuristic/Random.hpp
  isVerificationFile: false
  path: Heuristic/Simulated_Annealing.hpp
  requiredBy: []
  timestamp: '2026-07-21 00:54:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Heuristic/Simulated_Annealing.hpp
layout: document
redirect_from:
- /library/Heuristic/Simulated_Annealing.hpp
- /library/Heuristic/Simulated_Annealing.hpp.html
title: Heuristic/Simulated_Annealing.hpp
---
