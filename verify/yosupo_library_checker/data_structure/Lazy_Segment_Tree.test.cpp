#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include"../../../template/template.hpp"
#include"../../../modint.hpp"
#include"../../../Segment_Tree/Lazy_Segment_Tree.hpp"

using L = modint<998244353>;
using M = pair<L, int>;
using F = pair<L, L>;

auto op = [](M x, M y) -> M {
    auto first  = x.first  + y.first;
    auto second = x.second + y.second;
    return { first, second };
};

auto act = [](F a, M x) -> M {
    auto first  = a.first * x.first + a.second * x.second;
    auto second = x.second;
    return { first, second };
};

auto comp = [](F a, F b) -> F {
    auto first  = a.first * b.first;
    auto second = a.first * b.second + a.second;
    return { first, second };
};

M unit = make_pair(0, 0);
F id = make_pair(1, 0);

int main(){
    int N, Q; cin >> N >> Q;

    vector<M> a(N);
    for (int i = 0; i < N; i++){
        int x; scanf("%d", &x);
        a[i] = {x, 1};
    }

    Lazy_Segment_Tree<M, F> S(a, op, unit, act, comp, id);

    for (int q = 0; q < Q; q++){
        int t, l, r;
        scanf("%d", &t);

        if (t == 0){
            int b, c;
            scanf("%d%d%d%d", &l, &r, &b, &c);
            S.action(l, r - 1, {b, c});
        } elif (t == 1) {
            scanf("%d%d", &l, &r);
            cout << S.product(l, r - 1).first << "\n";
        }
    }
}

