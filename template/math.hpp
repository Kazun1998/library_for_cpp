#pragma once

// 演算子
template<typename T>
T add(const T &x, const T &y) { return x + y; }

template<typename T>
T sub(const T &x, const T &y) { return x - y; }

template<typename T>
T mul(const T &x, const T &y) { return x * y; }

template<typename T>
T neg(const T &x) { return -x; }

template<typename T>
T bitwise_and(const T &x, const T &y) { return x & y; }

template<typename T>
T bitwise_or(const T &x, const T &y) { return x | y; }

template<typename T>
T bitwise_xor(const T &x, const T &y) { return x ^ y; }

// 除算に関する関数

// floor(x / y) を求める.
template<typename T, typename U>
auto div_floor(T x, U y){
    return x / y - ((x % y != 0) && ((x < 0) != (y < 0)));
}

// ceil(x / y) を求める.
template<typename T, typename U>
auto div_ceil(T x, U y){
    return x / y + ((x % y != 0) && ((x < 0) == (y < 0)));
}

// x を y で割った余りを求める.
template<typename T, typename U>
T safe_mod(T x, U y){
    T q = div_floor(x, y);
    return x - q * y ;
}

// x を y で割った商と余りを求める.
template<typename T, typename U>
pair<T, T> divmod(T x, U y){
    T q = div_floor(x, y);
    return {q, x - q * y};
}

// 四捨五入を求める.
template<typename T, typename U>
auto round(T x, U y){
    T q, r;
    tie (q, r) = divmod(x, y);
    if (y < 0) return (r <= div_floor(y, 2)) ? q + 1 : q;
    return (r >= div_ceil(y, 2)) ? q + 1 : q;
}

// 指数に関する関数

// x の y 乗を求める.
ll intpow(ll x, ll y){
    ll a = 1;
    while (y){
        if (y & 1) { a *= x; }
        x *= x;
        y >>= 1;
    }
    return a;
}

// x の y 乗を z で割った余りを求める.
ll modpow(ll x, ll y, ll z){
    ll a = 1;
    while (y){
        if (y & 1) { (a *= x) %= z; }
        (x *= x) %= z;
        y >>= 1;
    }
    return a;
}

// x の y 乗を z で割った余りを求める.
template<typename T, typename U>
T modpow(T x, U y, T z) {
    T a = 1;
    while (y) {
        if (y & 1) { (a *= x) %= z; }

        (x *= x) %= z;
        y >>= 1;
    }

    return a;
}

// vector の要素の総和を求める.
ll sum(vector<ll> &X){
    ll y = 0;
    for (auto &&x: X) { y+=x; }
    return y;
}

// vector の要素の総和を求める.
template<typename T>
T sum(vector<T> &X){
    T y = T(0);
    for (auto &&x: X) { y += x; }
    return y;
}

template<typename T>
T sum(const vector<T> &X) {
    T y = T(0);
    for (auto &&x: X) { y += x; }
    return y;
}

// a x + b y = gcd(a, b) を満たす整数の組 (a, b) に対して, (x, y, gcd(a, b)) を求める.
template<integral T>
tuple<T, T, T> Extended_Euclid(T a, T b) {
    T s = 1, t = 0, u = 0, v = 1;
    while (b) {
        T q;
        tie(q, a, b) = make_tuple(div_floor(a, b), b, safe_mod(a, b));
        tie(s, t) = make_pair(t, s - q * t);
        tie(u, v) = make_pair(v, u - q * v);
    }

    return make_tuple(s, u, a);
}

// floor(sqrt(N)) を求める (N < 0 のときは, 0 とする).
ll isqrt(const ll &N) { 
    if (N <= 0) { return 0; }

    ll x = sqrt(N);
    while ((x + 1) * (x + 1) <= N) { x++; }
    while (x * x > N) { x--; }

    return x;
}

// floor(sqrt(N)) を求める (N < 0 のときは, 0 とする).
ll floor_sqrt(const ll &N) { return isqrt(N); }

// ceil(sqrt(N)) を求める (N < 0 のときは, 0 とする).
ll ceil_sqrt(const ll &N) {
    ll x = isqrt(N);
    return x * x == N ? x : x + 1;
}
