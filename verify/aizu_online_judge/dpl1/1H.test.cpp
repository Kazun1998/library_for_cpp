#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_H"

#include"../../../template/template.hpp"
#include"../../../Knapsack/Knapsack_01.hpp"

using namespace knapsack_problem;


int main() {
    int N; ll W; cin >> N >> W;
    vector<Item<int, ll, ll>> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << Knapsack_01<int, ll, ll, int>::solve_meet_in_the_middle(items, W).total_value << endl;
}