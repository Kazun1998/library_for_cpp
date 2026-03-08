#define PROBLEM "https://judge.yosupo.jp/problem/stern_brocot_tree"

#include"../../../template/template.hpp"
#include"../../../Math/Stern_Brocot_Tree.hpp"

Stern_Brocot_Tree::Path<char> encode_path() {
    int a, b; scanf("%d%d", &a, &b);
    return Stern_Brocot_Tree::encode(a, b, 'L', 'R');
}

Stern_Brocot_Tree::Fraction decode_path() {
    int k; cin >> k;
    Stern_Brocot_Tree::Path<char> path(k);
    for (int i = 0; i < k; i++) {
        scanf(" %c %lld", &path[i].first, &path[i].second);
    }

    return Stern_Brocot_Tree::decode(path, 'L', 'R');
}

Stern_Brocot_Tree::Fraction lca() {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    return Stern_Brocot_Tree::lowest_common_ancestor(a, b, c, d);
}

Stern_Brocot_Tree::Fraction ancestor() {
    int k, a, b; scanf("%d%d%d", &k, &a, &b);
    return Stern_Brocot_Tree::ancestor(a, b, k);
}

pair<Stern_Brocot_Tree::Fraction, Stern_Brocot_Tree::Fraction> range() {
    int a, b; scanf("%d%d", &a, &b);
    return Stern_Brocot_Tree::range(a, b);
}

int main() {
    int T; cin >> T;
    string type;

    for (int t = 0; t < T; t++) {
        cin >> type;
        if (type == "ENCODE_PATH") {
            Stern_Brocot_Tree::Path<char> path = encode_path();
            cout << path.size();
            for (pair<char, int> move: path) {
                cout << " " << move;
            }
            cout << "\n";
        } else if (type == "DECODE_PATH") {
            cout << decode_path() << "\n";
        } else if (type == "LCA") {
            cout << lca() << "\n";
        } else if (type == "ANCESTOR") {
            auto res = ancestor();
            if (res.second == -1) {
                cout << -1 << "\n";
            } else {
                cout << res << "\n";
            }
        } else if (type == "RANGE") {
            cout << range() << "\n";
        }
    }
}