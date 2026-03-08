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

// a の最大値を取得する.
template<typename T>
inline T max(const vector<T> &a){
    if (a.empty()) throw invalid_argument("vector is empty.");

    return *max_element(a.begin(), a.end());
}

// vector<T> a の最小値を取得する.
template<typename T>
inline T min(const vector<T> &a){
    if (a.empty()) throw invalid_argument("vector is empty.");

    return *min_element(a.begin(), a.end());
}

// vector<T> a の最大値のインデックスを取得する.
template<typename T>
inline size_t argmax(const vector<T> &a){
    if (a.empty()) throw std::invalid_argument("vector is empty.");

    return distance(a.begin(), max_element(a.begin(), a.end()));
}

// vector<T> a の最小値のインデックスを取得する.
template<typename T>
inline size_t argmin(const vector<T> &a){
    if (a.empty()) throw invalid_argument("vector is empty.");

    return distance(a.begin(), min_element(a.begin(), a.end()));
}
