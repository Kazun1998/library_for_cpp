#pragma once

#include "Summation.hpp"
#include <vector>
#include <algorithm>

namespace counting {
    /**
     * @brief 以下の条件を満たす整数の組 (x, y) の個数を求めます.
     * 
     * 条件: l <= x <= r, ax + b <= y <= cx + d
     * 
     * @tparam T 整数型
     * @param a 不等式 ax + b <= y の係数 a
     * @param b 不等式 ax + b <= y の定数 b
     * @param c 不等式 y <= cx + d の係数 c
     * @param d 不等式 y <= cx + d の定数 d
     * @param l x の下限
     * @param r x の上限
     * @return T 条件を満たす (x, y) の個数
     */
    template<typename T>
    T count_between_lines(T a, T b, T c, T d, T l, T r) {
        return summation::relu_linear(c - a, d - b + 1, l, r);
    }

    /**
     * @brief 以下の条件を満たす整数の組 (x, y) の個数を求めます.
     * 
     * 条件: l <= x <= r, ax + b <= y <= cx + d, ex + f <= y <= gx + h
     * 
     * @tparam T 整数型
     * @param a 不等式 ax + b <= y の係数 a
     * @param b 不等式 ax + b <= y の定数 b
     * @param c 不等式 y <= cx + d の係数 c
     * @param d 不等式 y <= cx + d の定数 d
     * @param e 不等式 ex + f <= y の係数 e
     * @param f 不等式 ex + f <= y の定数 f
     * @param g 不等式 y <= gx + h の係数 g
     * @param h 不等式 y <= gx + h の定数 h
     * @param l x の下限
     * @param r x の上限
     * @return T 条件を満たす (x, y) の個数
     */
    template<typename T>
    T count_between_lines(T a, T b, T c, T d, T e, T f, T g, T h, T l, T r) {
        // 各 x に対して y の個数は
        // max(0, min(cx + d, gx + h) - max(ax + b, ex + f) + 1)
        // = max(0, min(
        //    (c - a)x + (d - b + 1),
        //    (c - e)x + (d - f + 1),
        //    (g - a)x + (h - b + 1),
        //    (g - e)x + (h - f + 1)
        // ))
        // となる. 4つの直線の最小値(ただし負なら0)の和を求める問題に帰着される.

        struct Line { T k, m; };
        std::vector<Line> lines = {
            {c - a, d - b + 1},
            {c - e, d - f + 1},
            {g - a, h - b + 1},
            {g - e, h - f + 1}
        };

        T L = l, R = r;

        // 値が負になる範囲を除外する (L_i(x) >= 0 を満たす範囲に限定)
        for (const auto& line : lines) {
            if (line.k == 0) {
                if (line.m < 0) return 0;
            } else if (line.k > 0) {
                L = max<T>(L, div_ceil(-line.m, line.k));
            } else {
                R = min<T>(R, div_floor(-line.m, line.k));
            }
        }

        if (L > R) return 0;

        vector<T> points;
        points.push_back(L - 1);
        points.push_back(R);

        // 直線の交点を求めて区間を分割する
        for (size_t i = 0; i < lines.size(); ++i) {
            for (size_t j = i + 1; j < lines.size(); ++j) {
                if (lines[i].k == lines[j].k) continue;

                T num = lines[j].m - lines[i].m;
                T den = lines[i].k - lines[j].k;
                T x = div_floor(num, den);
                if (x >= L - 1 && x < R) points.push_back(x);
            }
        }

        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());

        T total = 0;
        for (size_t i = 0; i < points.size() - 1; ++i) {
            T seg_l = points[i] + 1;
            T seg_r = points[i+1];
            
            // 区間内では最小値を与える直線は変わらないので, 先頭の点で判定する
            T min_val = lines[0].k * seg_l + lines[0].m;
            size_t min_idx = 0;
            for (size_t j = 1; j < lines.size(); ++j) {
                T val = lines[j].k * seg_l + lines[j].m;
                if (val < min_val) {
                    min_val = val;
                    min_idx = j;
                }
            }
            
            total += summation::linear(lines[min_idx].k, lines[min_idx].m, seg_l, seg_r);
        }

        return total;
    }
}