#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include"../../../template/template.hpp"
#include"../../../Data_Structure/Dual_Heap.hpp"

int main() {
    int N, Q; cin >> N >> Q;
    vector<int> S(N); cin >> S;

    Dual_Heap<int> D(S);

    for (int q = 1; q <= Q; q++) {
        int t; cin >> t;
        if (t == 0) {
            int x; cin >> x;
            D.push(x);
        } else if (t == 1) {
            cout << D.pop_min() << endl;
        } else if (t == 2) { 
            cout << D.pop_max() << endl;
        }
    }
}
