#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../../../template/template.hpp"
#include "../../../String/Suffix_Array.hpp"

int main() {
    string S; cin >> S;
    cout << Suffix_Array(S) << endl;
}
