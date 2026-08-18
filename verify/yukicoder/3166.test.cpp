#define PROBLEM "https://yukicoder.me/problems/no/3166"

#include "../../template/template.hpp"
#include "../../Imos/Sparse_Cyclic_Imos_1.hpp"
#include "../../Binary_Search/General_Integer.hpp"

int verify() {
    int N, L, K; cin >> N >> L >> K;
    auto X = input_vector<int>(N);

    auto check = [&](int P) -> bool {
        auto I = Sparse_Cyclic_Imos_1<int>(L);
        for (int x: X) {
            I.add_forward(x - P, 2 * P, 1);
        }

        auto J = I.cumulative();
        return all_of(J.begin(), J.end(), [&K](const auto interval) -> bool {
            auto [S, _1, _2] = interval;
            return S >= K;
        });
    };

    return General_Binary_Increase_Search_Integer<int>(0, L, check, 0);
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << verify() << endl;
    }
}
