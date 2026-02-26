#define PROBLEM "https://judge.yosupo.jp/problem/rational_approximation"

#include"../../../template/template.hpp"
#include"../../../Math/Stern_Brocot_Tree.hpp"

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++){
        int N, x, y; scanf("%d%d%d", &N, &x, &y);
        Stern_Brocot_Tree::Fraction f, g;
        tie (ignore, g) = Stern_Brocot_Tree::binary_search_range_increase(N, [&x, &y](const ll a, const ll b) -> bool { return a * y >= b * x;});
        tie (f, ignore) = Stern_Brocot_Tree::binary_search_range_increase(N, [&x, &y](const ll a, const ll b) -> bool { return a * y > b * x;});

        cout << f << " " << g << "\n";
    }
}