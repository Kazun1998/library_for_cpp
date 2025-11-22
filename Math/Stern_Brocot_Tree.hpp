#pragma once

#include"../template/template.hpp"

struct Stern_Brocot_Tree {
    using Fraction = pair<ll, ll>;
    template<typename Direction>
    using Path = vector<pair<Direction, ll>>;

    /// @brief SB 木における 1/1 から a/b へのパスを求める.
    /// @tparam Direction 向きを表す値を格納するクラス
    /// @param a 分子
    /// @param b 分母
    /// @param left 左 (0/1 への向き) を表す値
    /// @param right 右 (1/0 への向き) を表す値
    /// @return pair<Direction, ll> 型の (d, k) からなるリスト. (d, k) は d の向きへ k 回連続で進むことを表す.
    template<typename Direction>
    static Path<Direction> encode(ll a, ll b, Direction left, Direction right) {
        Path<Direction> path;
        ll q, r;
        tie (q, r) = divmod(a, b);
        if (q > 0) { path.emplace_back(right, q); }

        a = b;
        b = r;
        bool parity = true;
        while (b > 0) {
            tie (q, r) = divmod(a, b);
            Direction direction = parity ? left : right;
            path.emplace_back(direction, q);

            tie (a, b) = make_tuple(b, r);
            parity = !parity;
        }

        if (path.back().second > 1) {
            path.back().second--;
        } else {
            path.pop_back();
        }

        return path;
    }

    /// @brief SB 木における 1/1 から code に沿って, 到達の可能性がある有理数の集合は有理数開区間になる. この有理数開区間の下限と上限を求める.
    /// @param code pair<Direction, ll> 型の (d, k) からなるリスト. (d, k) は d の向きへ k 回連続で進むことを表す.
    /// @param left 左 (0/1 への向き) を表す値
    /// @param right 右 (1/0 への向き) を表す値
    /// @return `pair<Fraction, Fraction>` {{下限分子, 下限分母}, {上限分子, 上限分母}}
    template<typename Direction>
    static pair<Fraction, Fraction> decode_interval(Path<Direction> &code, Direction left, Direction right) {
        ll p = 0, q = 1, r = 1, s = 0;
        for (auto &&[direction, k]: code) {
            if (direction == left) {
                r += k * p;
                s += k * q;
            } else {
                p += k * r;
                q += k * s;
            }
        }

        return {{p, q}, {r, s}}; 
    }

    /// @brief SB 木における 1/1 から移動した際の有理数を求める.
    /// @tparam Direction code における向きを格納するクラス
    /// @param code pair<Direction, ll> 型の (d, k) からなるリスト. (d, k) は d の向きへ k 回連続で進むことを表す.
    /// @param left 左 (0/1 への向き) を表す値
    /// @param right 右 (1/0 への向き) を表す値
    template<typename Direction>
    static Fraction decode(Path<Direction> &code, Direction left, Direction right) {
        auto &&[x, y] = decode_interval(code, left, right);
        auto &&[p, q] = x;
        auto &&[r, s] = y;
        return { p + r, q + s };
    }

    /// @brief SB 木における a/b と c/d の最小共通祖先を求める
    /// @param a 有理数 1 の分子
    /// @param b 有理数 1 の分母
    /// @param c 有理数 2 の分子
    /// @param d 有理数 2 の分母
    /// @return {分子, 分母} の形の pair<ll, ll>
    static Fraction lowest_common_ancestor(ll a, ll b, ll c, ll d) {
        if ((a == 1 && b == 1) || (c == 1 && d == 1)) {
            return {1, 1};
        }

        Path<bool> code_1 = encode(a, b, true, false);
        Path<bool> code_2 = encode(c, d, true, false);

        if (code_1.front().first != code_2.front().first) { return {1, 1}; }

        Path<bool> lca_code;
        for (int i = 0; i < min(code_1.size(), code_2.size()); i++) {
            bool t; ll k, l;
            tie (t, k) = code_1[i];
            tie (ignore, l) = code_2[i];

            lca_code.emplace_back(t, min(k, l));
            if (k != l) { break; }
        }

        return decode(lca_code, true, false);
    }

    /// @brief SB 木における有理数 a/b の深さ
    /// @param a 分子
    /// @param b 分母
    static ll depth(ll a, ll b) {
        ll res = 0;
        for (auto &&[ignore, k]: encode(a, b, true, false)) { res += k; }

        return res;
    }

    /// @brief SB 木における有理数 a/b の祖先で深さが k である有理数を求める.
    /// @param a 基準となる有理数の分子
    /// @param b 基準となる有理数の分母
    /// @param k 求める有理数の深さ
    /// @param default_value 存在しない場合の返り値
    /// @return {分子, 分母} の形の pair<ll, ll>
    static Fraction ancestor(ll a, ll b, ll k, Fraction default_value = {-1, -1}) {
        Path<bool> code;
        for (auto &&[direction, l]: encode(a, b, true, false)) {
            l = min(k, l);
            code.emplace_back(direction, l);
            k -= l;
            if (k == 0) { return decode(code, true, false); }
        }

        return default_value;
    }

    /// @brief SB 木における有理数 a/b の子孫の集合はある有理数開区間になる. この有理数開区間の下限と上限を求める.
    /// @param a 分子
    /// @param b 分母
    /// @return pair<pair<ll, ll>, pair<ll, ll>> の形のペア. それぞれ {{下限分子, 下限分母}, {上限分子, 上限分母}}
    static pair<Fraction, Fraction> range(ll a, ll b) {
        auto code = encode(a, b, true, false);
        return decode_interval(code, true, false);
    }

    /// @brief 単調増加な check において, cond(x) = T となる最小の x を挟む分子と分母が N 以下の有理数を求める.
    /// @param N 分子と分母の上限
    /// @param cond 2 変数関数で, cond(a, b) は cond(a / b) を意味する.
    /// @return 
    static pair<Fraction, Fraction> binary_search_range_increase(ll N, function<bool(ll, ll)> cond) {
        // x + d * y <= N ?
        auto is_valid = [&N](const ll x, const ll y, const ll d) -> bool {
            if (y == 0) { return x <= N; }

            return d <= (N - x) / y;
        };

        auto right_search = [&N, &cond, &is_valid](const ll p, const ll q, const ll r, const ll s) -> ll {
            ll lower = 0, upper = (N - p) / r + 1;
            while (upper - lower > 1) {
                ll d = (lower + upper) / 2;
                if (is_valid(p, r, d) && is_valid(q, s, d) && !cond(p + d * r, q + d * s)) {
                    lower = d;
                } else {
                    upper = d;
                }
            }

            return lower;
        };

        auto left_search = [&N, &cond, &is_valid](const ll p, const ll q, const ll r, const ll s) -> ll {
            ll lower = 0, upper = (N - p) / r + 1;
            while (upper - lower > 1) {
                ll d = (lower + upper) / 2;
                if (is_valid(r, p, d) && is_valid(s, q, d) && cond(r + d * p, s + d * q)) {
                    lower = d;
                } else {
                    upper = d;
                }
            }

            return lower;
        };

        ll p = 0, q = 1, r = 1, s = 0;
        while (p + r <= N && q + s <= N) {
            ll d;
            d = right_search(p, q, r, s);
            p += d * r; q += d * s;

            d = left_search(p, q, r, s);
            r += d * p; s += d * q;
        }

        return {{p, q}, {r, s}};
    }
};
