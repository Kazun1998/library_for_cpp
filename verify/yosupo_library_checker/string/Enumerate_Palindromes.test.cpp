#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include"../../../template/template.hpp"
#include"../../../String/Manacher.hpp"

int main() {
    string S; cin >> S;
    cout << Manacher(S) << endl;
}
