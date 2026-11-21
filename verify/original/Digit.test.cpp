#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template/template.hpp"
#include "../../Integer/Digit.hpp"

// b^i を計算する (オーバーフローしない範囲で使う)
ll naive_pow(ll b, int i) {
    ll res = 1;
    for (int k = 0; k < i; k++) { res *= b; }
    return res;
}

// b 進表記の桁数の愚直計算: b^d > n となる最小の d
int naive_length(ll n, ll b) {
    int d = 0;
    for (__int128 p = 1; p <= n; p *= b) { d++; }
    return d;
}

// digits が n の b 進表記の条件 (定理 1) を満たすかを判定する
bool is_representation(const vector<ll> &digits, ll n, ll b) {
    if (n == 0) { return digits == vector<ll>{0}; }
    if (digits.empty() || digits.front() == 0) { return false; }

    __int128 value = 0;
    for (ll x : digits) {
        if (x < 0 || x >= b) { return false; }
        value = value * b + x;
    }
    return value == n;
}

void verify() {
    // 具体的な値
    {
        assert((Integer_Digits(12345) == vector<ll>{1, 2, 3, 4, 5}));
        assert((Integer_Digits(10, 2) == vector<ll>{1, 0, 1, 0}));
        assert((Integer_Digits(255, 16) == vector<ll>{15, 15}));
        assert((Integer_Digits(0) == vector<ll>{0}));

        assert(Integer_Length(0) == 0);
        assert(Integer_Length(9) == 1);
        assert(Integer_Length(999) == 3);
        assert(Integer_Length(1000) == 4);
        assert(Integer_Length(1024, 2) == 11);

        assert(Digit_Sum(0) == 0);
        assert(Digit_Sum(12345) == 15);
        assert(Digit_Sum(255, 2) == 8);

        assert((Digit_Count(1122333) == vector<ll>{0, 2, 2, 3, 0, 0, 0, 0, 0, 0}));
        assert((Digit_Count(0) == vector<ll>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
        assert((Digit_Count(10, 2) == vector<ll>{2, 2}));

        assert(From_Digits({1, 2, 3, 4, 5}) == 12345);
        assert(From_Digits({1, 0, 1, 0}, 2) == 10);
        assert(From_Digits({}) == 0);
        assert(From_Digits({0, 0, 7}) == 7);
    }

    // 長さ l の指定
    {
        assert((Integer_Digits(5, 2, 6) == vector<ll>{0, 0, 0, 1, 0, 1}));
        assert((Integer_Digits(12345, 10, 3) == vector<ll>{3, 4, 5}));
        assert((Integer_Digits(12345, 10, 5) == vector<ll>{1, 2, 3, 4, 5}));
        assert((Integer_Digits(0, 10, 3) == vector<ll>{0, 0, 0}));
        assert(Integer_Digits(12345, 10, 0).empty());
    }

    // 不正な底では BaseException が送出される
    {
        for (ll b : {1LL, 0LL, -3LL}) {
            bool thrown;

            thrown = false;
            try { Integer_Digits(10, b); } catch (const BaseException &) { thrown = true; }
            assert(thrown);

            thrown = false;
            try { Integer_Length(10, b); } catch (const BaseException &) { thrown = true; }
            assert(thrown);

            thrown = false;
            try { Digit_Sum(10, b); } catch (const BaseException &) { thrown = true; }
            assert(thrown);

            thrown = false;
            try { Digit_Count(10, b); } catch (const BaseException &) { thrown = true; }
            assert(thrown);

            thrown = false;
            try { From_Digits({1, 0}, b); } catch (const BaseException &) { thrown = true; }
            assert(thrown);
        }
    }

    // 小さい n, b での総当たり (定義との突き合わせ)
    {
        for (ll b = 2; b <= 12; b++) {
            for (ll n = 0; n <= 3000; n++) {
                vector<ll> digits = Integer_Digits(n, b);
                assert(is_representation(digits, n, b));
                assert(From_Digits(digits, b) == n);

                assert(Integer_Length(n, b) == naive_length(n, b));

                ll sum = 0;
                vector<ll> count(b, 0);
                for (ll x : digits) { sum += x; count[x]++; }
                if (n == 0) { count[0] = 1; }
                assert(Digit_Sum(n, b) == sum);
                assert(Digit_Count(n, b) == count);

                // l を指定したときは, 下から l 桁 ((n / b^i) mod b) を並べたものになる
                for (int l = 0; l <= 8; l++) {
                    vector<ll> expected(l);
                    for (int i = 0; i < l; i++) {
                        __int128 p = 1;
                        for (int k = 0; k < i; k++) { p *= b; }
                        expected[l - 1 - i] = (ll)((n / p) % b);
                    }
                    assert(Integer_Digits(n, b, l) == expected);
                }
            }
        }
    }

    // 命題 4 (n ≡ S_b(n) mod (b-1)) と命題 7 (数字根の公式)
    {
        for (ll b = 2; b <= 20; b++) {
            for (ll n = 0; n <= 5000; n++) {
                assert((n - Digit_Sum(n, b)) % (b - 1) == 0);

                ll r = n;
                while (r >= b) { r = Digit_Sum(r, b); }

                ll expected;
                if (n == 0) { expected = 0; }
                else if (n % (b - 1) != 0) { expected = n % (b - 1); }
                else { expected = b - 1; }
                assert(r == expected);
            }
        }
    }

    // 大きな値
    {
        const ll M = LLONG_MAX;
        assert(Integer_Length(M) == 19);
        assert(Integer_Length(M, 2) == 63);
        assert((Integer_Digits(M, 2) == vector<ll>(63, 1)));
        assert(Digit_Sum(M, 2) == 63);

        for (ll b : {2LL, 3LL, 7LL, 10LL, 16LL, 1000000007LL, 1000000000000000000LL, M}) {
            vector<ll> digits = Integer_Digits(M, b);
            assert(is_representation(digits, M, b));
            assert(From_Digits(digits, b) == M);
            assert(Integer_Length(M, b) == naive_length(M, b));
        }

        // b > N のときは 1 桁
        assert((Integer_Digits(12345, M) == vector<ll>{12345}));
        assert(Integer_Length(12345, M) == 1);
        assert(naive_pow(10, 18) == 1000000000000000000LL);
        assert((Integer_Digits(naive_pow(10, 18), naive_pow(10, 9)) == vector<ll>{1, 0, 0}));
    }
}

int main() {
    verify();
    cout << "Hello World" << endl;
}
