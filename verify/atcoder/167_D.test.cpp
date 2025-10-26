#define PROBLEM "https://atcoder.jp/contests/abc167/tasks/abc167_d"
#define IGNORE

#include"../../../library_for_cpp/template/template.hpp"
#include"../../../library_for_cpp/Functional_Graph/Functional_Graph.hpp"

int main() {
    int N; ll K;
    cin >> N >> K;
    vector<int> a(N + 1, 0);
    for (int i = 1; i <= N; i++) { scanf("%d", &a[i]); }

    Functional_Graph F(a);
    cout << F.calculate(1, K) << endl;
}
