#pragma once

// 非負整数 x の bit legnth を求める.
ll bit_length(ll x) {
    if (x == 0) { return 0; }
    return (sizeof(long) * CHAR_BIT) - __builtin_clzll(x);
}

// 非負整数 x の popcount を求める.
ll popcount(ll x) { return __builtin_popcountll(x); }

// 正の整数 x に対して, floor(log2(x)) を求める.
ll floor_log2(ll x) { return bit_length(x) - 1; }

// 正の整数 x に対して, ceil(log2(x)) を求める.
ll ceil_log2(ll x) { return bit_length(x - 1); }

// x の第 k ビットを取得する
int get_bit(ll x, int k) { return (x >> k) & 1; }

// x のビット列を取得する.
// k はビット列の長さとする.
vector<int> get_bits(ll x, int k) {
    vector<int> bits(k);
    rep(i, k) {
        bits[i] = x & 1;
        x >>= 1;
    }

    return bits;
}

// x のビット列を取得する.
vector<int> get_bits(ll x) { return get_bits(x, bit_length(x)); }
