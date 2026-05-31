#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include "../../../template/template.hpp"
#include "../../../String/Longest_Common_Substring.hpp"

int main() {
    string S, T; cin >> S >> T;
    auto [a, b, c, d] = Longest_Common_Substring(S, T);
    cout << a << " " << b + 1 << " "<< c << " " << d + 1 << endl;
}
