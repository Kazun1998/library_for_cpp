#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B"

#include"../../../template/template.hpp"
#include"../../../Knapsack/Knapsack_01.hpp"

using namespace knapsack_problem;


int main() {
    int N, W; cin >> N >> W;
    vector<Item<int, int, int>> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << Knapsack_01<int, int, int>::solve_by_weight(items, W).total_value << endl;
}