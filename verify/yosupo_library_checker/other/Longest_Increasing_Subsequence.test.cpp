#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include"../../../template/template.hpp"
#include"../../../Sequence/Longest_Increasing_Subsequence.hpp"

int main() {
    int N; cin >> N;
    vector<int> A(N); cin >> A;

    Longest_Increasing_Subsequence<int> B(A, false);

    cout << B.length << endl;
    cout << B.index << endl;
}
