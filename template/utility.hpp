#pragma once

using ll = long long;

// a ← max(a, b) を実行する. a が更新されたら, 返り値が true.
template<typename T, typename U>
inline bool chmax(T &a, const U b){
    return (a < b ? a = b, 1: 0);
}

// a ← min(a, b) を実行する. a が更新されたら, 返り値が true.
template<typename T, typename U>
inline bool chmin(T &a, const U b){
    return (a > b ? a = b, 1: 0);
}
