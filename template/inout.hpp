// 入出力
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
vector<T> vector_input(int N, int index){
    vector<T> X(N+index);
    for (int i=index; i<index+N; i++) cin >> X[i];
    return X;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &X){
    for (auto &x: X) { is >> x; }
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &X){
    int s = (int)X.size();
    for (int i = 0; i < s; i++) { os << (i ? " " : "") << X[i]; }
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &S){
    int i = 0;
    for (T a: S) {os << (i ? " ": "") << a; i++;}
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const set<T> &S){
    int i = 0;
    for (T a: S) { os << (i ? " ": "") << a; i++; }
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &S){
    int i = 0;
    for (T a: S) { os << (i ? " ": "") << a; i++; }
    return os;
}

template<typename T>
ostream &operator<<(ostream &os, const multiset<T> &S){
    int i = 0;
    for (T a: S) { os << (i ? " ": "") << a; i++; }
    return os;
}

template<typename T>
std::vector<T> input_vector(size_t n, size_t offset = 0) {
    std::vector<T> res;
    // 最初に必要な全容量を確保（再確保を防ぐ）
    res.reserve(n + offset);
    // offset 分をデフォルト値で埋める（特別 indexed 用）
    res.assign(offset, T());
    
    for (size_t i = 0; i < n; ++i) {
        T el;
        if (!(std::cin >> el)) break;
        res.push_back(std::move(el));
    }
    return res;
}
