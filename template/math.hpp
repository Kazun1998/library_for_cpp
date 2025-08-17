#pragma once

// 除算に関する関数

// floor(x / y) を求める.
template<typename T, typename U>
T div_floor(T x, U y){ return (x > 0 ? x / y: (x - y + 1) / y); }

// ceil(x / y) を求める.
template<typename T, typename U>
T div_ceil(T x, U y){ return (x > 0 ? (x + y - 1) / y: x / y) ;}

// x を y で割った余りを求める.
template<typename T, typename U>
T mod(T x, U y){
    T q = div_floor(x, y);
    return x - q * y ;
}

// x を y で割った商と余りを求める.
template<typename T, typename U>
pair<T, T> divmod(T x, U y){
    T q = floor(x, y);
    return {q, x - q * y};
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
