#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include"../../template/template.hpp"
#include"../../Integer/Integer_Inequality.hpp"

mt19937_64 rng(20260102);

ll rand_range(ll l, ll r) { return l + (ll)(rng() % (unsigned long long)(r - l + 1)); }

template<typename T>
__int128 eval(const vector<T> &P, ll x) {
    __int128 v = 0;
    for (int i = (int)P.size() - 1; i >= 0; i--) {
        v = v * x + (__int128)P[i];
    }
    return v;
}

// 愚直解: [l, r] 上で P(x) <= y (equal = false の場合は P(x) < y) となる最大の x
optional<ll> naive_inequality(const vector<ll> &P, ll y, ll l, ll r, bool equal) {
    optional<ll> res = nullopt;
    for (ll x = l; x <= r; x++) {
        __int128 v = eval(P, x);
        if (v < y || (equal && v == y)) { res = x; }
    }
    return res;
}

// 小さい多項式に対して, 愚直解と比較する (符号付き)
void verify_small_signed() {
    const ll R = 150;
    for (int iteration = 0; iteration < 20000; iteration++) {
        int n = rand_range(2, 5);
        vector<ll> P(n);
        for (auto &p: P) { p = rand_range(-5, 5); }
        if (P.back() <= 0) { P.back() = rand_range(1, 5); }

        ll l = rand_range(-10, 10);

        // [l, R] 上で狭義単調増加であるものだけを使う (係数が小さいため, R 以降も単調増加)
        bool increasing = true;
        for (ll x = l; x < R; x++) {
            if (eval(P, x) >= eval(P, x + 1)) { increasing = false; break; }
        }
        if (!increasing) { continue; }

        ll y = rand_range((ll)eval(P, l) - 5, (ll)eval(P, l + 30) + 5);

        for (bool equal: {true, false}) {
            assert(Integer_Inequality<ll>(P, y, l, equal) == naive_inequality(P, y, l, R, equal));
        }
    }
}

// 小さい多項式に対して, 愚直解と比較する (符号なし)
void verify_small_unsigned() {
    using U = unsigned long long;
    const ll R = 150;
    for (int iteration = 0; iteration < 20000; iteration++) {
        int n = rand_range(2, 5);
        vector<ll> P(n);
        for (auto &p: P) { p = rand_range(0, 5); }
        if (P.back() == 0) { P.back() = rand_range(1, 5); }
        // 非定数でなくてはならない
        bool constant = true;
        for (int i = 1; i < n; i++) { if (P[i] != 0) { constant = false; } }
        if (constant) { continue; }

        vector<U> Q(P.begin(), P.end());

        ll l = rand_range(0, 10);
        ll y = rand_range(0, (ll)eval(P, l + 30) + 5);

        for (bool equal: {true, false}) {
            assert(optional<ll>(Integer_Inequality<U>(Q, y, l, equal)) == naive_inequality(P, y, l, R, equal));
        }
    }
}

// 大きな値に対して, __int128 による二分探索と比較する.
// 多項式は c_0 + c_1 x + ... + c_k x^k (c_1, ..., c_k >= 0 かつ c_k > 0) の形にする (x >= 0 で狭義単調増加).
// 符号付きの場合は c_0 が負でもよい.
template<typename T>
void verify_large(bool allow_negative) {
    for (int iteration = 0; iteration < 3000; iteration++) {
        int n = rand_range(2, 4);
        vector<ll> P(n);
        for (int i = 1; i < n; i++) { P[i] = rand_range(0, 3); }
        P.back() = rand_range(1, 3);
        P[0] = rand_range(allow_negative ? -1000000000 : 0, 1000000000);

        ll l = rand_range(0, 5);
        ll y = rand_range(0, (ll)3e18);
        if (iteration % 3 == 0) { // 解が存在するようにする
            ll x = rand_range(l, 1000);
            __int128 v = eval(P, x);
            if (v < 0 || v > (__int128)3e18) { continue; }
            y = (ll)v;
        }

        // 基準: P(x) <= y を満たす最大の x (P(l) > y の場合は存在しない)
        auto reference = [&](bool equal) -> optional<ll> {
            auto ok = [&](ll x) {
                __int128 v = eval(P, x);
                return v < y || (equal && v == y);
            };
            if (!ok(l)) { return nullopt; }
            ll lo = l, hi = (n == 2) ? 4000000000000000000LL : 3000000000LL;
            while (hi - lo > 1) {
                ll c = (lo + hi) / 2;
                (ok(c) ? lo : hi) = c;
            }
            return lo;
        };

        vector<T> Q(P.begin(), P.end());

        for (bool equal: {true, false}) {
            optional<ll> expected = reference(equal);
            optional<T> actual = Integer_Inequality<T>(Q, (T)y, (T)l, equal);
            assert(actual.has_value() == expected.has_value());
            if (expected) { assert((ll)*actual == *expected); }
        }
    }
}

int main() {
    verify_small_signed();
    verify_small_unsigned();
    verify_large<ll>(true);
    verify_large<unsigned long long>(false);
    cout << "Hello World" << endl;
}
