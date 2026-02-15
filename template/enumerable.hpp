#pragma once

#include <vector>
#include <functional>
#include <type_traits>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <optional>
#include <stdexcept>
#include <utility>

namespace enumerable {
    /// @brief コンテナの各要素に関数を適用し、その結果を新しい `std::vector` として返す。
    ///
    /// Ruby の `Enumerable#collect` (または `map`) に相当します。C++の `std::transform` に似ていますが、常に出力として新しい `std::vector` を生成して返す点が異なります。
    /// @tparam Container イテレート可能なコンテナの型 (e.g., std::vector<T>)。
    /// @tparam Func 各要素に適用する関数の型。
    /// @param container 対象のコンテナ。
    /// @param func 各要素に適用する関数オブジェクト (ラムダ式など)。
    /// @return 関数の適用結果を格納した新しい `std::vector`。
    template <typename Container, typename Func>
    auto collect(const Container& container, const Func& func) {
        using ResultType = std::invoke_result_t<Func, typename Container::const_reference>;
        std::vector<ResultType> result;
        if constexpr (requires { std::size(container); }) {
            result.reserve(std::size(container));
        }
        for (const auto& element : container) {
            result.push_back(std::invoke(func, element));
        }
        return result;
    }

    /// @brief コンテナの各要素に対して述語関数を適用し、真を返した要素のみを格納した新しい `std::vector` を返す。
    ///
    /// Ruby の `Enumerable#select` や `Enumerable#filter` に相当します。
    /// @tparam Container イテレート可能なコンテナの型。
    /// @tparam Pred 各要素に対する条件判定を行う関数の型。
    /// @param container 対象のコンテナ。
    /// @param pred 各要素に対して真偽値を返す関数オブジェクト。
    /// @return 条件を満たす要素を格納した新しい `std::vector`。
    template <typename Container, typename Pred>
    auto select(const Container& container, const Pred& pred) {
        using T = std::decay_t<typename Container::const_reference>;
        std::vector<T> result;
        for (const auto& element : container) {
            if (std::invoke(pred, element)) {
                result.push_back(element);
            }
        }
        return result;
    }

    /// @brief コンテナの各要素に対して述語関数を適用し、偽を返した要素のみを格納した新しい `std::vector` を返す。
    ///
    /// Ruby の `Enumerable#reject` に相当します。
    /// @tparam Container イテレート可能なコンテナの型。
    /// @tparam Pred 各要素に対する条件判定を行う関数の型。
    /// @param container 対象のコンテナ。
    /// @param pred 各要素に対して真偽値を返す関数オブジェクト。
    /// @return 条件を満たさない（偽となる）要素を格納した新しい `std::vector`。
    template <typename Container, typename Pred>
    auto reject(const Container& container, const Pred& pred) {
        using T = std::decay_t<typename Container::const_reference>;
        std::vector<T> result;
        for (const auto& element : container) {
            if (!std::invoke(pred, element)) {
                result.push_back(element);
            }
        }
        return result;
    }

    /// @brief コンテナの要素を畳み込む。
    ///
    /// Ruby の `Enumerable#inject` (または `reduce`) に相当します。
    /// @param init 初期値。
    /// @param func 畳み込み関数 (accum, element) -> accum。
    template <typename Container, typename T, typename Func>
    auto inject(const Container& container, T init, Func func) {
        for (const auto& element : container) {
            init = std::invoke(func, init, element);
        }
        return init;
    }

    /// @brief コンテナの要素を畳み込む（初期値なし）。
    ///
    /// Ruby の `Enumerable#inject` (または `reduce`) に相当します。
    /// コンテナが空の場合は例外を投げます。
    template <typename Container, typename Func>
    auto inject(const Container& container, Func func) {
        auto it = std::begin(container);
        auto end = std::end(container);
        if (it == end) throw std::runtime_error("enumerable::inject: container is empty");
        // 値のコピーを作成してアキュムレータとする
        auto result = *it; 
        ++it;
        for (; it != end; ++it) {
            result = std::invoke(func, result, *it);
        }
        return result;
    }

    /// @brief すべての要素が条件を満たすか判定する。
    /// Ruby の `Enumerable#all?` に相当します。
    template <typename Container, typename Pred>
    bool all_of(const Container& container, Pred pred) {
        return std::all_of(std::begin(container), std::end(container), pred);
    }

    /// @brief いずれかの要素が条件を満たすか判定する。
    /// Ruby の `Enumerable#any?` に相当します。
    template <typename Container, typename Pred>
    bool any_of(const Container& container, Pred pred) {
        return std::any_of(std::begin(container), std::end(container), pred);
    }

    /// @brief すべての要素が条件を満たさないか判定する。
    /// Ruby の `Enumerable#none?` に相当します。
    template <typename Container, typename Pred>
    bool none_of(const Container& container, Pred pred) {
        return std::none_of(std::begin(container), std::end(container), pred);
    }

    /// @brief 指定した値が含まれているか判定する。
    /// Ruby の `Enumerable#include?` (または `member?`) に相当します。
    template <typename Container, typename T>
    bool include(const Container& container, const T& val) {
        return std::find(std::begin(container), std::end(container), val) != std::end(container);
    }

    /// @brief 条件を満たす最初の要素を返す。
    /// Ruby の `Enumerable#find` (または `detect`) に相当します。
    /// 見つからない場合は std::nullopt を返します。
    template <typename Container, typename Pred>
    auto find(const Container& container, Pred pred) -> std::optional<typename Container::value_type> {
        auto it = std::find_if(std::begin(container), std::end(container), pred);
        if (it != std::end(container)) return *it;
        return std::nullopt;
    }

    /// @brief 条件を満たす最初の要素のインデックスを返す。
    /// Ruby の `Enumerable#find_index` に相当します。
    /// 見つからない場合は std::nullopt を返します。
    template <typename Container, typename Pred>
    std::optional<size_t> find_index(const Container& container, Pred pred) {
        auto it = std::find_if(std::begin(container), std::end(container), pred);
        if (it != std::end(container)) return std::distance(std::begin(container), it);
        return std::nullopt;
    }

    /// @brief 条件を満たす要素の数を返す。
    /// Ruby の `Enumerable#count` (ブロック付き) に相当します。
    template <typename Container, typename Pred>
    size_t count(const Container& container, Pred pred) {
        return std::count_if(std::begin(container), std::end(container), pred);
    }

    /// @brief 条件を満たす要素と満たさない要素に分割する。
    /// Ruby の `Enumerable#partition` に相当します。
    /// @return {満たす要素のリスト, 満たさない要素のリスト} のペア
    template <typename Container, typename Pred>
    auto partition(const Container& container, Pred pred) {
        using T = typename Container::value_type;
        std::vector<T> true_list, false_list;
        for (const auto& element : container) {
            if (std::invoke(pred, element)) {
                true_list.push_back(element);
            } else {
                false_list.push_back(element);
            }
        }
        return std::make_pair(true_list, false_list);
    }

    /// @brief ブロックの評価結果ごとにグループ化する。
    /// Ruby の `Enumerable#group_by` に相当します。
    /// @return キー -> 要素リスト のマップ
    template <typename Container, typename Func>
    auto group_by(const Container& container, Func func) {
        using T = typename Container::value_type;
        using Key = std::invoke_result_t<Func, typename Container::const_reference>;
        std::map<Key, std::vector<T>> result;
        for (const auto& element : container) {
            result[std::invoke(func, element)].push_back(element);
        }
        return result;
    }

    /// @brief ブロックの評価結果を使ってソートする。
    /// Ruby の `Enumerable#sort_by` に相当します。
    template <typename Container, typename Func>
    auto sort_by(const Container& container, Func func) {
        using T = typename Container::value_type;
        using Key = std::decay_t<std::invoke_result_t<Func, typename Container::const_reference>>;
        
        std::vector<std::pair<Key, T>> pairs;
        if constexpr (requires { std::size(container); }) {
            pairs.reserve(std::size(container));
        }
        for (const auto& element : container) {
            pairs.emplace_back(std::invoke(func, element), element);
        }

        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });

        std::vector<T> result;
        result.reserve(pairs.size());
        for (const auto& p : pairs) {
            result.push_back(p.second);
        }
        return result;
    }

    /// @brief 重複を取り除いた新しいリストを返す（出現順を保持）。
    /// Ruby の `Enumerable#uniq` に相当します。
    template <typename Container>
    auto uniq(const Container& container) {
        using T = typename Container::value_type;
        std::vector<T> result;
        std::set<T> seen;
        for (const auto& element : container) {
            if (seen.find(element) == seen.end()) {
                seen.insert(element);
                result.push_back(element);
            }
        }
        return result;
    }

} // namespace enumerable
