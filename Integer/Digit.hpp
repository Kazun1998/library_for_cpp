#pragma once

#include"../template/template.hpp"

/**
 * @brief 不正な底が指定されたときにスローされるカスタム例外
 */
class BaseException : public runtime_error {
    private:
    ll error_base;

    public:
    /**
     * @brief BaseExceptionを構築します。
     * * @param base 不正な底の値
     */
    BaseException(ll base) :
        runtime_error("指定した底 " + to_string(base) + " は不正な底です."), 
        error_base(base) {}
};

/**
 * @brief 整数 n の底を b とした場合の表現を求める.
 *
 * @param n 符号は無視される
 * @param b 底 (b >= 2). Default to 10.
 * @param l 長さが 0 になるように左側に 0 を埋めたり, 右から l 要素を取得する. -1 は無指定.
 * @return vector<ll> 数のリスト (最上位桁から最下位桁の順).
 */
vector<ll> Integer_Digits(ll n, ll b = 10, int l = -1) {
    if (b < 2) { throw BaseException(b); }

    n = abs(n);
    vector<ll> digits;

    if (l == -1) {
        if (n == 0) {
            digits.push_back(0);
            return digits;
        }

        while (n > 0) {
            digits.push_back(n % b);
            n /= b;
        }
    } else {
        for (int i = 0; i < l; ++i) {
            digits.push_back(n % b);
            n /= b;
        }
    }

    reverse(digits.begin(), digits.end());
    return digits;
}

/**
 * @brief 整数 n の底を b とした場合の桁数を求める (0 は 0 桁とする).
 *
 * @param n 符号は無視される
 * @param b 底 (b >= 2). Default to 10.
 * @return int 桁数
 */
int Integer_Length(ll n, ll b = 10) {
    if (b < 2) { throw BaseException(b); }
    
    n = abs(n);
    
    int length = 0;
    for (; n > 0; length++) { n /= b; }

    return length;
}

/**
 * @brief 整数 n の底を b とした場合の桁和を求める.
 *
 * @param n 符号は無視される
 * @param b 底 (b >= 2). デフォルトは 10.
 * @return ll 桁和
 */
ll Digit_Sum(ll n, ll b = 10) {
    if (b < 2) { throw BaseException(b); }
    
    n = abs(n);
    
    ll sum = 0;
        
    while (n > 0) {
        sum += n % b;
        n /= b;
    }
    return sum;
}

/**
 * @brief 整数 n の底を b とした場合における各数の出現回数を求める.
 *
 * @param n 符号は無視される
 * @param b 底 (b >= 2). Default to 10.
 * @return vector<ll> 長さ b の配列. 第 k 要素は k の出現回数.
 */
vector<ll> Digit_Count(ll n, ll b = 10) {
    if (b < 2) { throw BaseException(b); }

    n = abs(n);

    vector<ll> count(b, 0);    
    for (ll d : Integer_Digits(n, b)) {
        count[d]++;
    }
    return count;
}

/**
 * @brief 底を b とした場合に digit がなす整数を返す (Integer_Digit の逆関数)
 *
 * @param digits 数のリスト (最上位桁から最下位桁の順)
 * @param b 底 (b >= 2). Default to 10.
 * @return ll 整数 (オーバーフローの可能性があるため注意)
 */
ll From_Digits(const vector<ll> &digits, ll b = 10) {
    if (b < 2) { throw BaseException(b); }

    ll res = 0;
    for (ll x : digits) {  res = b * res + x; }
    return res;
}
