#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include"../../../Integer/Primitive_Root.hpp"

uint64_t verify() {
    uint64_t p; cin >> p;
    return Find_Primitive_Root(p);
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++){
        cout << verify() << endl;
    }
}
