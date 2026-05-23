#pragma once

#include "../template/template.hpp"

/**
 * @brief Suffix Array を構築する.
 * 
 * ダブリングと基数ソートを用いて O(N log N) で構築する.
 * 返り値 sa は, sa[i] が「辞書順で i 番目に小さい接尾辞の開始インデックス」となるようなサイズ N の配列.
 * 空文字列（番兵）は内部的な構築過程でのみ利用され、返り値には含まれない.
 * 
 * @tparam T 配列の要素の型. std::integral コンセプトを満たす必要がある.
 * @param A 構築対象の配列
 * @return vector<int> 構築された Suffix Array
 */
template<integral T>
vector<int> Suffix_Array(const vector<T> &A) {
    int n = A.size();
    // 空文字列（番兵）を含めたサイズ n+1 で管理
    vector<int> suffix_array(n + 1);
    vector<int> rank(n + 1);     // 各接尾辞の現在のランク
    vector<int> tmp_sa(n + 1);
    vector<int> tmp_rank(n + 1);

    // 1文字目による初期ソート
    iota(suffix_array.begin(), suffix_array.end(), 0);
    sort(suffix_array.begin(), suffix_array.end(), [&](int i, int j) {
        // 番兵 (index n) を最小として扱う
        if (i == n) return true;
        if (j == n) return false;
        return A[i] < A[j];
    });

    rank[suffix_array[0]] = 0;
    int r = 0;
    for (int i = 1; i <= n; ++i) {
        if (suffix_array[i - 1] == n || (suffix_array[i] != n && A[suffix_array[i - 1]] < A[suffix_array[i]])) r++;
        rank[suffix_array[i]] = r;
    }
    
    // ダブリング: 長さ k の比較結果から長さ 2k の比較結果を導出する
    for (int k = 1; k <= n; k <<= 1) {
        // 第2キー (rank[i+k]) に基づいて tmp_sa を構成
        int it = 0;
        // 後半部分が存在しない (i+k > n) 接尾辞が最小
        for (int i = n - k + 1; i <= n; ++i) tmp_sa[it++] = i;
        // それ以外を直前の suffix_array の順序（長さ k での順序）を利用して並べる
        for (int i = 0; i <= n; ++i) {
            if (suffix_array[i] >= k) tmp_sa[it++] = suffix_array[i] - k;
        }

        // 第1キー (rank[i]) に基づいて計数ソート（Counting Sort）を行う
        // これにより (rank[i], rank[i+k]) のペアでソートしたことになる
        vector<int> cnt(r + 1, 0);
        for (int i = 0; i <= n; ++i) cnt[rank[i]]++;
        for (int i = 1; i <= r; ++i) cnt[i] += cnt[i - 1];
        // 安定ソートを維持するため後ろから走査
        for (int i = n; i >= 0; --i) suffix_array[--cnt[rank[tmp_sa[i]]]] = tmp_sa[i];

        tmp_rank[suffix_array[0]] = 0;
        r = 0;
        auto first = [&](int idx) { return rank[idx]; };
        auto second = [&](int idx) { return (idx + k <= n) ? rank[idx + k] : -1; };
        for (int i = 1; i <= n; ++i) {
            // 前の要素と (第1キー, 第2キー) のペアが異なる場合にランクを上げる
            unless (first(suffix_array[i - 1]) == first(suffix_array[i]) && second(suffix_array[i - 1]) == second(suffix_array[i])) r++;
            tmp_rank[suffix_array[i]] = r;
        }
        rank = tmp_rank;
        // すべてのランクが異なれば（一意に定まれば）終了
        if (r == n) break;
    }

    // 先頭の番兵 (n) を削除
    suffix_array.erase(suffix_array.begin());

    return suffix_array;
}

/**
 * @brief 整数型以外の要素を持つ配列に対して Suffix Array を構築する.
 *
 * 内部で座標圧縮を行い, 整数型の Suffix Array 構築関数を呼び出す.
 * 計算量は座標圧縮を含めて O(N log N) となる.
 *
 * @tparam T 配列の要素の型. !std::integral かつ std::totally_ordered コンセプトを満たす必要がある.
 * @param A 構築対象の配列
 * @return vector<int> Suffix Array
 */
template<typename T>
requires (!integral<T> && totally_ordered<T>)
vector<int> Suffix_Array(const vector<T> &A) {
    int n = A.size();

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return A[i] < A[j]; });

    vector<int> B(n);
    int r = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && A[idx[i - 1]] < A[idx[i]]) r++;
        B[idx[i]] = r;
    }
    return Suffix_Array<int>(B);
}

/**
 * @brief 文字列に対して Suffix Array を構築する.
 *
 * 内部で vector<char> に変換して処理を行うラップ関数.
 *
 * @param S 構築対象の文字列
 * @return vector<int> Suffix Array
 */
vector<int> Suffix_Array(const string &S) {
    return Suffix_Array<char>(vector<char>(S.begin(), S.end()));
}
