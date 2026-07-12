// 入出力
#include <type_traits>
#include <string>

template<class... T>
void input(T&... a){ (cin >> ... >> a); }

void print(){ cout << "\n"; }

template<class T, class... Ts>
void print(const T& a, const Ts&... b){
    cout << a;
    (cout << ... << (cout << " ", b));
    cout << "\n";
}

template<typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &P){
    is >> P.first >> P.second;
    return is;
}

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &P){
    os << P.first << " " << P.second;
    return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &X){
    for (auto &x: X) { is >> x; }
    return is;
}

template<typename T, typename U = typename T::iterator>
typename std::enable_if<!std::is_same<T, std::string>::value, ostream&>::type
operator<<(ostream &os, const T &container){
    bool is_first = true;
    for (const auto &x : container) {
        os << (is_first ? "" : " ") << x;
        is_first = false;
    }
    return os;
}

template<typename T>
std::vector<T> input_vector(int n, int offset = 0) {
    std::vector<T> res;
    // 最初に必要な全容量を確保（再確保を防ぐ）
    res.reserve(n + offset);
    // offset 分をデフォルト値で埋める（特別 indexed 用）
    res.assign(offset, T());

    for (int i = 0; i < n; ++i) {
        T el;
        if (!(std::cin >> el)) break;
        res.push_back(std::move(el));
    }
    return res;
}

#include <vector>

// 1. 終端：サイズ n の 1 次元 vector を作る
template<typename T>
auto make_multi_dimensional_vector(int n) {
    return std::vector<T>(n);
}

// 2. 終端：サイズ n で初期値 val を持つ 1 次元 vector を作る（オーバーロード）
template<typename T>
auto make_multi_dimensional_vector(int n, T val) {
    return std::vector<T>(n, val);
}

// 3. 再帰：次元を削る
template<typename T, typename... Args>
auto make_multi_dimensional_vector(int n, Args... args) {
    auto inner = make_multi_dimensional_vector<T>(args...);
    return std::vector<decltype(inner)>(n, inner);
}
