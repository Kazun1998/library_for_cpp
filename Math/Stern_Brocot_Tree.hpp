#pragma once

#include"../template/template.hpp"

struct Stern_Brocot_Tree {
    using Fraction = pair<ll, ll>;
    template<typename Direction>
    using Path = vector<pair<Direction, ll>>;

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

    template<typename Direction>
    static Fraction decode(Path<Direction> &code, Direction left, Direction right) {
        auto &&[x, y] = decode_interval(code, left, right);
        auto &&[p, q] = x;
        auto &&[r, s] = y;
        return { p + r, q + s };
    }

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

    static ll depth(ll a, ll b) {
        ll res = 0;
        for (auto &&[ignore, k]: encode(a, b, true, false)) { res += k; }

        return res;
    }

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

    static pair<Fraction, Fraction> range(ll a, ll b) {
        auto code = encode(a, b, true, false);
        return decode_interval(code, true, false);
    }
};
