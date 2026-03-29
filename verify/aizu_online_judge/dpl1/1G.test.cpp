#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_G"

#include"../../../template/template.hpp"
#include"../../../Knapsack/Knapsack_Limitation.hpp"

using namespace knapsack_problem;


int main() {
    int N, W; cin >> N >> W;
    vector<Item<int, int, int>> items(N);
    vector<int> limit(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].value >> items[i].weight >> limit[i];
    }

    cout << Knapsack_Limitation<int, int, int, int>::solve_by_weight(items, limit, W).total_value << endl;
}
