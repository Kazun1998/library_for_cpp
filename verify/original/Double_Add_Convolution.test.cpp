#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template/template.hpp"
#include "../../Convolution/Double_Add_Convolution.hpp"

using convolution::Double_Add_Convolution;

vector<ll> naive_convolution(const vector<ll> &A, const vector<ll> &B) {
    if (A.empty() || B.empty()) { return {}; }

    vector<ll> C(A.size() + B.size() - 1, 0);
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < B.size(); j++) {
            C[i + j] += A[i] * B[j];
        }
    }
    return C;
}

void verify() {
    // 空配列
    {
        assert(Double_Add_Convolution::convolution({}, {1, 2, 3}).empty());
        assert(Double_Add_Convolution::convolution({1, 2, 3}, {}).empty());
    }

    // 小さな例
    {
        vector<ll> A{1, 2, 3}, B{4, 5, 6};
        vector<ll> C = Double_Add_Convolution::convolution(A, B);
        vector<ll> expected{4, 13, 28, 27, 18};

        assert(C == expected);
    }

    // ランダムなサイズ・値に対して naive 実装と一致するかを確認
    {
        mt19937 mt(12345);
        uniform_int_distribution<int> size_dist(0, 130);
        uniform_int_distribution<ll> value_dist(-100, 100);

        for (int t = 0; t < 100; t++) {
            int n = size_dist(mt), m = size_dist(mt);

            vector<ll> A(n), B(m);
            for (ll &x: A) { x = value_dist(mt); }
            for (ll &x: B) { x = value_dist(mt); }

            vector<ll> C = Double_Add_Convolution::convolution(A, B);
            vector<ll> expected = naive_convolution(A, B);

            assert(C == expected);
        }
    }
}

int main() {
    verify();
    cout << "Hello World" << endl;
}
