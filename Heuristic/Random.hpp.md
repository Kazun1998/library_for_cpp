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
    links: []
  bundledCode: "#line 2 \"Heuristic/Random.hpp\"\n#include <random>\n\n// \u7AF6\u6280\
    \u30D7\u30ED\u30B0\u30E9\u30DF\u30F3\u30B0\uFF08\u30DE\u30E9\u30BD\u30F3\u30DE\
    \u30C3\u30C1\uFF09\u7528\u306E\u4E71\u6570\u751F\u6210\u30AF\u30E9\u30B9\nclass\
    \ Random {\npublic:\n    // \u30B7\u30FC\u30C9\u3092\u6307\u5B9A\u3057\u3066\u521D\
    \u671F\u5316\uFF08\u30C7\u30D5\u30A9\u30EB\u30C8\u306F\u56FA\u5B9A\u5024\u3067\
    \u518D\u73FE\u6027\u3092\u62C5\u4FDD\uFF09\n    explicit Random(uint32_t seed\
    \ = 42) : engine(seed) {}\n\n    // [min_val, max_val] \u306E\u7BC4\u56F2\u306E\
    \u6574\u6570\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u751F\u6210\u3059\u308B\uFF08\
    \u4E21\u7AEF\u542B\u3080\uFF09\n    // @param min_val \u6700\u5C0F\u5024\n   \
    \ // @param max_val \u6700\u5927\u5024\n    // @return \u751F\u6210\u3055\u308C\
    \u305F\u4E71\u6570\n    int next_int(int min_val, int max_val) {\n        std::uniform_int_distribution<int>\
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
    \        return dist(engine);\n    }\n\nprivate:\n    std::mt19937 engine;\n};\n"
  code: "#pragma once\n#include <random>\n\n// \u7AF6\u6280\u30D7\u30ED\u30B0\u30E9\
    \u30DF\u30F3\u30B0\uFF08\u30DE\u30E9\u30BD\u30F3\u30DE\u30C3\u30C1\uFF09\u7528\
    \u306E\u4E71\u6570\u751F\u6210\u30AF\u30E9\u30B9\nclass Random {\npublic:\n  \
    \  // \u30B7\u30FC\u30C9\u3092\u6307\u5B9A\u3057\u3066\u521D\u671F\u5316\uFF08\
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
    \        return dist(engine);\n    }\n\nprivate:\n    std::mt19937 engine;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Heuristic/Random.hpp
  requiredBy:
  - Heuristic/Simulated_Annealing.hpp
  timestamp: '2026-07-21 00:54:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Heuristic/Random.hpp
layout: document
redirect_from:
- /library/Heuristic/Random.hpp
- /library/Heuristic/Random.hpp.html
title: Heuristic/Random.hpp
---
