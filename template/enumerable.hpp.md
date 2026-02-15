---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/original/enumerable.test.cpp
    title: verify/original/enumerable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B3\u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u95A2\u6570\
      \u3092\u9069\u7528\u3057\u3001\u305D\u306E\u7D50\u679C\u3092\u65B0\u3057\u3044\
      \ `std::vector` \u3068\u3057\u3066\u8FD4\u3059\u3002"
    links: []
  bundledCode: "#line 2 \"template/enumerable.hpp\"\n\n#include <vector>\n#include\
    \ <functional>\n#include <type_traits>\n#include <iterator>\n#include <algorithm>\n\
    #include <map>\n#include <set>\n#include <optional>\n#include <stdexcept>\n#include\
    \ <utility>\n\nnamespace enumerable {\n    /// @brief \u30B3\u30F3\u30C6\u30CA\
    \u306E\u5404\u8981\u7D20\u306B\u95A2\u6570\u3092\u9069\u7528\u3057\u3001\u305D\
    \u306E\u7D50\u679C\u3092\u65B0\u3057\u3044 `std::vector` \u3068\u3057\u3066\u8FD4\
    \u3059\u3002\n    ///\n    /// Ruby \u306E `Enumerable#collect` (\u307E\u305F\u306F\
    \ `map`) \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002C++\u306E `std::transform`\
    \ \u306B\u4F3C\u3066\u3044\u307E\u3059\u304C\u3001\u5E38\u306B\u51FA\u529B\u3068\
    \u3057\u3066\u65B0\u3057\u3044 `std::vector` \u3092\u751F\u6210\u3057\u3066\u8FD4\
    \u3059\u70B9\u304C\u7570\u306A\u308A\u307E\u3059\u3002\n    /// @tparam Container\
    \ \u30A4\u30C6\u30EC\u30FC\u30C8\u53EF\u80FD\u306A\u30B3\u30F3\u30C6\u30CA\u306E\
    \u578B (e.g., std::vector<T>)\u3002\n    /// @tparam Func \u5404\u8981\u7D20\u306B\
    \u9069\u7528\u3059\u308B\u95A2\u6570\u306E\u578B\u3002\n    /// @param container\
    \ \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\u3002\n    /// @param func \u5404\
    \u8981\u7D20\u306B\u9069\u7528\u3059\u308B\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8 (\u30E9\u30E0\u30C0\u5F0F\u306A\u3069)\u3002\n    /// @return \u95A2\
    \u6570\u306E\u9069\u7528\u7D50\u679C\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\
    \u3044 `std::vector`\u3002\n    template <typename Container, typename Func>\n\
    \    auto collect(const Container& container, const Func& func) {\n        using\
    \ ResultType = std::invoke_result_t<Func, typename Container::const_reference>;\n\
    \        std::vector<ResultType> result;\n        if constexpr (requires { std::size(container);\
    \ }) {\n            result.reserve(std::size(container));\n        }\n       \
    \ for (const auto& element : container) {\n            result.push_back(std::invoke(func,\
    \ element));\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u8FF0\u8A9E\
    \u95A2\u6570\u3092\u9069\u7528\u3057\u3001\u771F\u3092\u8FD4\u3057\u305F\u8981\
    \u7D20\u306E\u307F\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\
    \ \u3092\u8FD4\u3059\u3002\n    ///\n    /// Ruby \u306E `Enumerable#select` \u3084\
    \ `Enumerable#filter` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @tparam\
    \ Container \u30A4\u30C6\u30EC\u30FC\u30C8\u53EF\u80FD\u306A\u30B3\u30F3\u30C6\
    \u30CA\u306E\u578B\u3002\n    /// @tparam Pred \u5404\u8981\u7D20\u306B\u5BFE\u3059\
    \u308B\u6761\u4EF6\u5224\u5B9A\u3092\u884C\u3046\u95A2\u6570\u306E\u578B\u3002\
    \n    /// @param container \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\u3002\n\
    \    /// @param pred \u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u771F\u507D\u5024\
    \u3092\u8FD4\u3059\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3002\n   \
    \ /// @return \u6761\u4EF6\u3092\u6E80\u305F\u3059\u8981\u7D20\u3092\u683C\u7D0D\
    \u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\n    template <typename Container,\
    \ typename Pred>\n    auto select(const Container& container, const Pred& pred)\
    \ {\n        using T = std::decay_t<typename Container::const_reference>;\n  \
    \      std::vector<T> result;\n        for (const auto& element : container) {\n\
    \            if (std::invoke(pred, element)) {\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u8FF0\u8A9E\
    \u95A2\u6570\u3092\u9069\u7528\u3057\u3001\u507D\u3092\u8FD4\u3057\u305F\u8981\
    \u7D20\u306E\u307F\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\
    \ \u3092\u8FD4\u3059\u3002\n    ///\n    /// Ruby \u306E `Enumerable#reject` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @tparam Container \u30A4\u30C6\u30EC\
    \u30FC\u30C8\u53EF\u80FD\u306A\u30B3\u30F3\u30C6\u30CA\u306E\u578B\u3002\n   \
    \ /// @tparam Pred \u5404\u8981\u7D20\u306B\u5BFE\u3059\u308B\u6761\u4EF6\u5224\
    \u5B9A\u3092\u884C\u3046\u95A2\u6570\u306E\u578B\u3002\n    /// @param container\
    \ \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\u3002\n    /// @param pred \u5404\
    \u8981\u7D20\u306B\u5BFE\u3057\u3066\u771F\u507D\u5024\u3092\u8FD4\u3059\u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3002\n    /// @return \u6761\u4EF6\
    \u3092\u6E80\u305F\u3055\u306A\u3044\uFF08\u507D\u3068\u306A\u308B\uFF09\u8981\
    \u7D20\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\n \
    \   template <typename Container, typename Pred>\n    auto reject(const Container&\
    \ container, const Pred& pred) {\n        using T = std::decay_t<typename Container::const_reference>;\n\
    \        std::vector<T> result;\n        for (const auto& element : container)\
    \ {\n            if (!std::invoke(pred, element)) {\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u8981\u7D20\u3092\u7573\u307F\u8FBC\u3080\u3002\n   \
    \ ///\n    /// Ruby \u306E `Enumerable#inject` (\u307E\u305F\u306F `reduce`) \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @param init \u521D\u671F\u5024\u3002\
    \n    /// @param func \u7573\u307F\u8FBC\u307F\u95A2\u6570 (accum, element) ->\
    \ accum\u3002\n    template <typename Container, typename T, typename Func>\n\
    \    auto inject(const Container& container, T init, Func func) {\n        for\
    \ (const auto& element : container) {\n            init = std::invoke(func, init,\
    \ element);\n        }\n        return init;\n    }\n\n    /// @brief \u30B3\u30F3\
    \u30C6\u30CA\u306E\u8981\u7D20\u3092\u7573\u307F\u8FBC\u3080\uFF08\u521D\u671F\
    \u5024\u306A\u3057\uFF09\u3002\n    ///\n    /// Ruby \u306E `Enumerable#inject`\
    \ (\u307E\u305F\u306F `reduce`) \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n \
    \   /// \u30B3\u30F3\u30C6\u30CA\u304C\u7A7A\u306E\u5834\u5408\u306F\u4F8B\u5916\
    \u3092\u6295\u3052\u307E\u3059\u3002\n    template <typename Container, typename\
    \ Func>\n    auto inject(const Container& container, Func func) {\n        auto\
    \ it = std::begin(container);\n        auto end = std::end(container);\n     \
    \   if (it == end) throw std::runtime_error(\"enumerable::inject: container is\
    \ empty\");\n        // \u5024\u306E\u30B3\u30D4\u30FC\u3092\u4F5C\u6210\u3057\
    \u3066\u30A2\u30AD\u30E5\u30E0\u30EC\u30FC\u30BF\u3068\u3059\u308B\n        auto\
    \ result = *it; \n        ++it;\n        for (; it != end; ++it) {\n         \
    \   result = std::invoke(func, result, *it);\n        }\n        return result;\n\
    \    }\n\n    /// @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u304B\u5224\u5B9A\u3059\u308B\u3002\n    /// Ruby \u306E\
    \ `Enumerable#all?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename\
    \ Container, typename Pred>\n    bool all_of(const Container& container, Pred\
    \ pred) {\n        return std::all_of(std::begin(container), std::end(container),\
    \ pred);\n    }\n\n    /// @brief \u3044\u305A\u308C\u304B\u306E\u8981\u7D20\u304C\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u5224\u5B9A\u3059\u308B\u3002\n   \
    \ /// Ruby \u306E `Enumerable#any?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\
    \n    template <typename Container, typename Pred>\n    bool any_of(const Container&\
    \ container, Pred pred) {\n        return std::any_of(std::begin(container), std::end(container),\
    \ pred);\n    }\n\n    /// @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u6761\
    \u4EF6\u3092\u6E80\u305F\u3055\u306A\u3044\u304B\u5224\u5B9A\u3059\u308B\u3002\
    \n    /// Ruby \u306E `Enumerable#none?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\
    \n    template <typename Container, typename Pred>\n    bool none_of(const Container&\
    \ container, Pred pred) {\n        return std::none_of(std::begin(container),\
    \ std::end(container), pred);\n    }\n\n    /// @brief \u6307\u5B9A\u3057\u305F\
    \u5024\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\
    \u3002\n    /// Ruby \u306E `Enumerable#include?` (\u307E\u305F\u306F `member?`)\
    \ \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename Container,\
    \ typename T>\n    bool include(const Container& container, const T& val) {\n\
    \        return std::find(std::begin(container), std::end(container), val) !=\
    \ std::end(container);\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\u305F\
    \u3059\u6700\u521D\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\n    /// Ruby \u306E\
    \ `Enumerable#find` (\u307E\u305F\u306F `detect`) \u306B\u76F8\u5F53\u3057\u307E\
    \u3059\u3002\n    /// \u898B\u3064\u304B\u3089\u306A\u3044\u5834\u5408\u306F std::nullopt\
    \ \u3092\u8FD4\u3057\u307E\u3059\u3002\n    template <typename Container, typename\
    \ Pred>\n    auto find(const Container& container, Pred pred) -> std::optional<typename\
    \ Container::value_type> {\n        auto it = std::find_if(std::begin(container),\
    \ std::end(container), pred);\n        if (it != std::end(container)) return *it;\n\
    \        return std::nullopt;\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u6700\u521D\u306E\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3059\u3002\n    /// Ruby \u306E `Enumerable#find_index` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// \u898B\u3064\u304B\u3089\u306A\u3044\
    \u5834\u5408\u306F std::nullopt \u3092\u8FD4\u3057\u307E\u3059\u3002\n    template\
    \ <typename Container, typename Pred>\n    std::optional<size_t> find_index(const\
    \ Container& container, Pred pred) {\n        auto it = std::find_if(std::begin(container),\
    \ std::end(container), pred);\n        if (it != std::end(container)) return std::distance(std::begin(container),\
    \ it);\n        return std::nullopt;\n    }\n\n    /// @brief \u6761\u4EF6\u3092\
    \u6E80\u305F\u3059\u8981\u7D20\u306E\u6570\u3092\u8FD4\u3059\u3002\n    /// Ruby\
    \ \u306E `Enumerable#count` (\u30D6\u30ED\u30C3\u30AF\u4ED8\u304D) \u306B\u76F8\
    \u5F53\u3057\u307E\u3059\u3002\n    template <typename Container, typename Pred>\n\
    \    size_t count(const Container& container, Pred pred) {\n        return std::count_if(std::begin(container),\
    \ std::end(container), pred);\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u8981\u7D20\u3068\u6E80\u305F\u3055\u306A\u3044\u8981\u7D20\u306B\
    \u5206\u5272\u3059\u308B\u3002\n    /// Ruby \u306E `Enumerable#partition` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @return {\u6E80\u305F\u3059\u8981\
    \u7D20\u306E\u30EA\u30B9\u30C8, \u6E80\u305F\u3055\u306A\u3044\u8981\u7D20\u306E\
    \u30EA\u30B9\u30C8} \u306E\u30DA\u30A2\n    template <typename Container, typename\
    \ Pred>\n    auto partition(const Container& container, Pred pred) {\n       \
    \ using T = typename Container::value_type;\n        std::vector<T> true_list,\
    \ false_list;\n        for (const auto& element : container) {\n            if\
    \ (std::invoke(pred, element)) {\n                true_list.push_back(element);\n\
    \            } else {\n                false_list.push_back(element);\n      \
    \      }\n        }\n        return std::make_pair(true_list, false_list);\n \
    \   }\n\n    /// @brief \u30D6\u30ED\u30C3\u30AF\u306E\u8A55\u4FA1\u7D50\u679C\
    \u3054\u3068\u306B\u30B0\u30EB\u30FC\u30D7\u5316\u3059\u308B\u3002\n    /// Ruby\
    \ \u306E `Enumerable#group_by` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n  \
    \  /// @return \u30AD\u30FC -> \u8981\u7D20\u30EA\u30B9\u30C8 \u306E\u30DE\u30C3\
    \u30D7\n    template <typename Container, typename Func>\n    auto group_by(const\
    \ Container& container, Func func) {\n        using T = typename Container::value_type;\n\
    \        using Key = std::invoke_result_t<Func, typename Container::const_reference>;\n\
    \        std::map<Key, std::vector<T>> result;\n        for (const auto& element\
    \ : container) {\n            result[std::invoke(func, element)].push_back(element);\n\
    \        }\n        return result;\n    }\n\n    /// @brief \u30D6\u30ED\u30C3\
    \u30AF\u306E\u8A55\u4FA1\u7D50\u679C\u3092\u4F7F\u3063\u3066\u30BD\u30FC\u30C8\
    \u3059\u308B\u3002\n    /// Ruby \u306E `Enumerable#sort_by` \u306B\u76F8\u5F53\
    \u3057\u307E\u3059\u3002\n    template <typename Container, typename Func>\n \
    \   auto sort_by(const Container& container, Func func) {\n        using T = typename\
    \ Container::value_type;\n        using Key = std::decay_t<std::invoke_result_t<Func,\
    \ typename Container::const_reference>>;\n        \n        std::vector<std::pair<Key,\
    \ T>> pairs;\n        if constexpr (requires { std::size(container); }) {\n  \
    \          pairs.reserve(std::size(container));\n        }\n        for (const\
    \ auto& element : container) {\n            pairs.emplace_back(std::invoke(func,\
    \ element), element);\n        }\n\n        std::sort(pairs.begin(), pairs.end(),\
    \ [](const auto& a, const auto& b) {\n            return a.first < b.first;\n\
    \        });\n\n        std::vector<T> result;\n        result.reserve(pairs.size());\n\
    \        for (const auto& p : pairs) {\n            result.push_back(p.second);\n\
    \        }\n        return result;\n    }\n\n    /// @brief \u91CD\u8907\u3092\
    \u53D6\u308A\u9664\u3044\u305F\u65B0\u3057\u3044\u30EA\u30B9\u30C8\u3092\u8FD4\
    \u3059\uFF08\u51FA\u73FE\u9806\u3092\u4FDD\u6301\uFF09\u3002\n    /// Ruby \u306E\
    \ `Enumerable#uniq` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename\
    \ Container>\n    auto uniq(const Container& container) {\n        using T = typename\
    \ Container::value_type;\n        std::vector<T> result;\n        std::set<T>\
    \ seen;\n        for (const auto& element : container) {\n            if (seen.find(element)\
    \ == seen.end()) {\n                seen.insert(element);\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n} // namespace enumerable\n"
  code: "#pragma once\n\n#include <vector>\n#include <functional>\n#include <type_traits>\n\
    #include <iterator>\n#include <algorithm>\n#include <map>\n#include <set>\n#include\
    \ <optional>\n#include <stdexcept>\n#include <utility>\n\nnamespace enumerable\
    \ {\n    /// @brief \u30B3\u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u95A2\
    \u6570\u3092\u9069\u7528\u3057\u3001\u305D\u306E\u7D50\u679C\u3092\u65B0\u3057\
    \u3044 `std::vector` \u3068\u3057\u3066\u8FD4\u3059\u3002\n    ///\n    /// Ruby\
    \ \u306E `Enumerable#collect` (\u307E\u305F\u306F `map`) \u306B\u76F8\u5F53\u3057\
    \u307E\u3059\u3002C++\u306E `std::transform` \u306B\u4F3C\u3066\u3044\u307E\u3059\
    \u304C\u3001\u5E38\u306B\u51FA\u529B\u3068\u3057\u3066\u65B0\u3057\u3044 `std::vector`\
    \ \u3092\u751F\u6210\u3057\u3066\u8FD4\u3059\u70B9\u304C\u7570\u306A\u308A\u307E\
    \u3059\u3002\n    /// @tparam Container \u30A4\u30C6\u30EC\u30FC\u30C8\u53EF\u80FD\
    \u306A\u30B3\u30F3\u30C6\u30CA\u306E\u578B (e.g., std::vector<T>)\u3002\n    ///\
    \ @tparam Func \u5404\u8981\u7D20\u306B\u9069\u7528\u3059\u308B\u95A2\u6570\u306E\
    \u578B\u3002\n    /// @param container \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\
    \u3002\n    /// @param func \u5404\u8981\u7D20\u306B\u9069\u7528\u3059\u308B\u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8 (\u30E9\u30E0\u30C0\u5F0F\u306A\u3069\
    )\u3002\n    /// @return \u95A2\u6570\u306E\u9069\u7528\u7D50\u679C\u3092\u683C\
    \u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\n    template <typename\
    \ Container, typename Func>\n    auto collect(const Container& container, const\
    \ Func& func) {\n        using ResultType = std::invoke_result_t<Func, typename\
    \ Container::const_reference>;\n        std::vector<ResultType> result;\n    \
    \    if constexpr (requires { std::size(container); }) {\n            result.reserve(std::size(container));\n\
    \        }\n        for (const auto& element : container) {\n            result.push_back(std::invoke(func,\
    \ element));\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u8FF0\u8A9E\
    \u95A2\u6570\u3092\u9069\u7528\u3057\u3001\u771F\u3092\u8FD4\u3057\u305F\u8981\
    \u7D20\u306E\u307F\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\
    \ \u3092\u8FD4\u3059\u3002\n    ///\n    /// Ruby \u306E `Enumerable#select` \u3084\
    \ `Enumerable#filter` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @tparam\
    \ Container \u30A4\u30C6\u30EC\u30FC\u30C8\u53EF\u80FD\u306A\u30B3\u30F3\u30C6\
    \u30CA\u306E\u578B\u3002\n    /// @tparam Pred \u5404\u8981\u7D20\u306B\u5BFE\u3059\
    \u308B\u6761\u4EF6\u5224\u5B9A\u3092\u884C\u3046\u95A2\u6570\u306E\u578B\u3002\
    \n    /// @param container \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\u3002\n\
    \    /// @param pred \u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u771F\u507D\u5024\
    \u3092\u8FD4\u3059\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3002\n   \
    \ /// @return \u6761\u4EF6\u3092\u6E80\u305F\u3059\u8981\u7D20\u3092\u683C\u7D0D\
    \u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\n    template <typename Container,\
    \ typename Pred>\n    auto select(const Container& container, const Pred& pred)\
    \ {\n        using T = std::decay_t<typename Container::const_reference>;\n  \
    \      std::vector<T> result;\n        for (const auto& element : container) {\n\
    \            if (std::invoke(pred, element)) {\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u5404\u8981\u7D20\u306B\u5BFE\u3057\u3066\u8FF0\u8A9E\
    \u95A2\u6570\u3092\u9069\u7528\u3057\u3001\u507D\u3092\u8FD4\u3057\u305F\u8981\
    \u7D20\u306E\u307F\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\
    \ \u3092\u8FD4\u3059\u3002\n    ///\n    /// Ruby \u306E `Enumerable#reject` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @tparam Container \u30A4\u30C6\u30EC\
    \u30FC\u30C8\u53EF\u80FD\u306A\u30B3\u30F3\u30C6\u30CA\u306E\u578B\u3002\n   \
    \ /// @tparam Pred \u5404\u8981\u7D20\u306B\u5BFE\u3059\u308B\u6761\u4EF6\u5224\
    \u5B9A\u3092\u884C\u3046\u95A2\u6570\u306E\u578B\u3002\n    /// @param container\
    \ \u5BFE\u8C61\u306E\u30B3\u30F3\u30C6\u30CA\u3002\n    /// @param pred \u5404\
    \u8981\u7D20\u306B\u5BFE\u3057\u3066\u771F\u507D\u5024\u3092\u8FD4\u3059\u95A2\
    \u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3002\n    /// @return \u6761\u4EF6\
    \u3092\u6E80\u305F\u3055\u306A\u3044\uFF08\u507D\u3068\u306A\u308B\uFF09\u8981\
    \u7D20\u3092\u683C\u7D0D\u3057\u305F\u65B0\u3057\u3044 `std::vector`\u3002\n \
    \   template <typename Container, typename Pred>\n    auto reject(const Container&\
    \ container, const Pred& pred) {\n        using T = std::decay_t<typename Container::const_reference>;\n\
    \        std::vector<T> result;\n        for (const auto& element : container)\
    \ {\n            if (!std::invoke(pred, element)) {\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n    /// @brief \u30B3\
    \u30F3\u30C6\u30CA\u306E\u8981\u7D20\u3092\u7573\u307F\u8FBC\u3080\u3002\n   \
    \ ///\n    /// Ruby \u306E `Enumerable#inject` (\u307E\u305F\u306F `reduce`) \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @param init \u521D\u671F\u5024\u3002\
    \n    /// @param func \u7573\u307F\u8FBC\u307F\u95A2\u6570 (accum, element) ->\
    \ accum\u3002\n    template <typename Container, typename T, typename Func>\n\
    \    auto inject(const Container& container, T init, Func func) {\n        for\
    \ (const auto& element : container) {\n            init = std::invoke(func, init,\
    \ element);\n        }\n        return init;\n    }\n\n    /// @brief \u30B3\u30F3\
    \u30C6\u30CA\u306E\u8981\u7D20\u3092\u7573\u307F\u8FBC\u3080\uFF08\u521D\u671F\
    \u5024\u306A\u3057\uFF09\u3002\n    ///\n    /// Ruby \u306E `Enumerable#inject`\
    \ (\u307E\u305F\u306F `reduce`) \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n \
    \   /// \u30B3\u30F3\u30C6\u30CA\u304C\u7A7A\u306E\u5834\u5408\u306F\u4F8B\u5916\
    \u3092\u6295\u3052\u307E\u3059\u3002\n    template <typename Container, typename\
    \ Func>\n    auto inject(const Container& container, Func func) {\n        auto\
    \ it = std::begin(container);\n        auto end = std::end(container);\n     \
    \   if (it == end) throw std::runtime_error(\"enumerable::inject: container is\
    \ empty\");\n        // \u5024\u306E\u30B3\u30D4\u30FC\u3092\u4F5C\u6210\u3057\
    \u3066\u30A2\u30AD\u30E5\u30E0\u30EC\u30FC\u30BF\u3068\u3059\u308B\n        auto\
    \ result = *it; \n        ++it;\n        for (; it != end; ++it) {\n         \
    \   result = std::invoke(func, result, *it);\n        }\n        return result;\n\
    \    }\n\n    /// @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u304B\u5224\u5B9A\u3059\u308B\u3002\n    /// Ruby \u306E\
    \ `Enumerable#all?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename\
    \ Container, typename Pred>\n    bool all_of(const Container& container, Pred\
    \ pred) {\n        return std::all_of(std::begin(container), std::end(container),\
    \ pred);\n    }\n\n    /// @brief \u3044\u305A\u308C\u304B\u306E\u8981\u7D20\u304C\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u304B\u5224\u5B9A\u3059\u308B\u3002\n   \
    \ /// Ruby \u306E `Enumerable#any?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\
    \n    template <typename Container, typename Pred>\n    bool any_of(const Container&\
    \ container, Pred pred) {\n        return std::any_of(std::begin(container), std::end(container),\
    \ pred);\n    }\n\n    /// @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u304C\u6761\
    \u4EF6\u3092\u6E80\u305F\u3055\u306A\u3044\u304B\u5224\u5B9A\u3059\u308B\u3002\
    \n    /// Ruby \u306E `Enumerable#none?` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\
    \n    template <typename Container, typename Pred>\n    bool none_of(const Container&\
    \ container, Pred pred) {\n        return std::none_of(std::begin(container),\
    \ std::end(container), pred);\n    }\n\n    /// @brief \u6307\u5B9A\u3057\u305F\
    \u5024\u304C\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\
    \u3002\n    /// Ruby \u306E `Enumerable#include?` (\u307E\u305F\u306F `member?`)\
    \ \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename Container,\
    \ typename T>\n    bool include(const Container& container, const T& val) {\n\
    \        return std::find(std::begin(container), std::end(container), val) !=\
    \ std::end(container);\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\u305F\
    \u3059\u6700\u521D\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\n    /// Ruby \u306E\
    \ `Enumerable#find` (\u307E\u305F\u306F `detect`) \u306B\u76F8\u5F53\u3057\u307E\
    \u3059\u3002\n    /// \u898B\u3064\u304B\u3089\u306A\u3044\u5834\u5408\u306F std::nullopt\
    \ \u3092\u8FD4\u3057\u307E\u3059\u3002\n    template <typename Container, typename\
    \ Pred>\n    auto find(const Container& container, Pred pred) -> std::optional<typename\
    \ Container::value_type> {\n        auto it = std::find_if(std::begin(container),\
    \ std::end(container), pred);\n        if (it != std::end(container)) return *it;\n\
    \        return std::nullopt;\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u6700\u521D\u306E\u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3059\u3002\n    /// Ruby \u306E `Enumerable#find_index` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// \u898B\u3064\u304B\u3089\u306A\u3044\
    \u5834\u5408\u306F std::nullopt \u3092\u8FD4\u3057\u307E\u3059\u3002\n    template\
    \ <typename Container, typename Pred>\n    std::optional<size_t> find_index(const\
    \ Container& container, Pred pred) {\n        auto it = std::find_if(std::begin(container),\
    \ std::end(container), pred);\n        if (it != std::end(container)) return std::distance(std::begin(container),\
    \ it);\n        return std::nullopt;\n    }\n\n    /// @brief \u6761\u4EF6\u3092\
    \u6E80\u305F\u3059\u8981\u7D20\u306E\u6570\u3092\u8FD4\u3059\u3002\n    /// Ruby\
    \ \u306E `Enumerable#count` (\u30D6\u30ED\u30C3\u30AF\u4ED8\u304D) \u306B\u76F8\
    \u5F53\u3057\u307E\u3059\u3002\n    template <typename Container, typename Pred>\n\
    \    size_t count(const Container& container, Pred pred) {\n        return std::count_if(std::begin(container),\
    \ std::end(container), pred);\n    }\n\n    /// @brief \u6761\u4EF6\u3092\u6E80\
    \u305F\u3059\u8981\u7D20\u3068\u6E80\u305F\u3055\u306A\u3044\u8981\u7D20\u306B\
    \u5206\u5272\u3059\u308B\u3002\n    /// Ruby \u306E `Enumerable#partition` \u306B\
    \u76F8\u5F53\u3057\u307E\u3059\u3002\n    /// @return {\u6E80\u305F\u3059\u8981\
    \u7D20\u306E\u30EA\u30B9\u30C8, \u6E80\u305F\u3055\u306A\u3044\u8981\u7D20\u306E\
    \u30EA\u30B9\u30C8} \u306E\u30DA\u30A2\n    template <typename Container, typename\
    \ Pred>\n    auto partition(const Container& container, Pred pred) {\n       \
    \ using T = typename Container::value_type;\n        std::vector<T> true_list,\
    \ false_list;\n        for (const auto& element : container) {\n            if\
    \ (std::invoke(pred, element)) {\n                true_list.push_back(element);\n\
    \            } else {\n                false_list.push_back(element);\n      \
    \      }\n        }\n        return std::make_pair(true_list, false_list);\n \
    \   }\n\n    /// @brief \u30D6\u30ED\u30C3\u30AF\u306E\u8A55\u4FA1\u7D50\u679C\
    \u3054\u3068\u306B\u30B0\u30EB\u30FC\u30D7\u5316\u3059\u308B\u3002\n    /// Ruby\
    \ \u306E `Enumerable#group_by` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n  \
    \  /// @return \u30AD\u30FC -> \u8981\u7D20\u30EA\u30B9\u30C8 \u306E\u30DE\u30C3\
    \u30D7\n    template <typename Container, typename Func>\n    auto group_by(const\
    \ Container& container, Func func) {\n        using T = typename Container::value_type;\n\
    \        using Key = std::invoke_result_t<Func, typename Container::const_reference>;\n\
    \        std::map<Key, std::vector<T>> result;\n        for (const auto& element\
    \ : container) {\n            result[std::invoke(func, element)].push_back(element);\n\
    \        }\n        return result;\n    }\n\n    /// @brief \u30D6\u30ED\u30C3\
    \u30AF\u306E\u8A55\u4FA1\u7D50\u679C\u3092\u4F7F\u3063\u3066\u30BD\u30FC\u30C8\
    \u3059\u308B\u3002\n    /// Ruby \u306E `Enumerable#sort_by` \u306B\u76F8\u5F53\
    \u3057\u307E\u3059\u3002\n    template <typename Container, typename Func>\n \
    \   auto sort_by(const Container& container, Func func) {\n        using T = typename\
    \ Container::value_type;\n        using Key = std::decay_t<std::invoke_result_t<Func,\
    \ typename Container::const_reference>>;\n        \n        std::vector<std::pair<Key,\
    \ T>> pairs;\n        if constexpr (requires { std::size(container); }) {\n  \
    \          pairs.reserve(std::size(container));\n        }\n        for (const\
    \ auto& element : container) {\n            pairs.emplace_back(std::invoke(func,\
    \ element), element);\n        }\n\n        std::sort(pairs.begin(), pairs.end(),\
    \ [](const auto& a, const auto& b) {\n            return a.first < b.first;\n\
    \        });\n\n        std::vector<T> result;\n        result.reserve(pairs.size());\n\
    \        for (const auto& p : pairs) {\n            result.push_back(p.second);\n\
    \        }\n        return result;\n    }\n\n    /// @brief \u91CD\u8907\u3092\
    \u53D6\u308A\u9664\u3044\u305F\u65B0\u3057\u3044\u30EA\u30B9\u30C8\u3092\u8FD4\
    \u3059\uFF08\u51FA\u73FE\u9806\u3092\u4FDD\u6301\uFF09\u3002\n    /// Ruby \u306E\
    \ `Enumerable#uniq` \u306B\u76F8\u5F53\u3057\u307E\u3059\u3002\n    template <typename\
    \ Container>\n    auto uniq(const Container& container) {\n        using T = typename\
    \ Container::value_type;\n        std::vector<T> result;\n        std::set<T>\
    \ seen;\n        for (const auto& element : container) {\n            if (seen.find(element)\
    \ == seen.end()) {\n                seen.insert(element);\n                result.push_back(element);\n\
    \            }\n        }\n        return result;\n    }\n\n} // namespace enumerable\n"
  dependsOn: []
  isVerificationFile: false
  path: template/enumerable.hpp
  requiredBy: []
  timestamp: '2026-02-15 10:09:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/original/enumerable.test.cpp
documentation_of: template/enumerable.hpp
layout: document
title: enumerable
---

## Outline

Ruby における Enumerable に関するメソッドの中で, 特に有用であるものを C++ に移植したもの.

参考: [Ruby 公式ドキュメントにおける Enumerable モジュールページ](https://docs.ruby-lang.org/ja/latest/class/Enumerable.html)

## History

|日付|内容|
|:---:|:---|
|2026/01/25| enumerable 系のメソッドを一括実装 |
