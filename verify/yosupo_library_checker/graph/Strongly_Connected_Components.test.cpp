#include"../../../template/template.hpp"
#include"../../../Graph/Digraph/Strongly_Connected_Components.hpp"

int main() {
    int N, M; cin >> N >> M;
    auto D = Digraph::Digraph(N);

    for (int j = 0; j < M; j++) {
        int a, b; scanf("%d%d", &a, &b);
        D.add_arc(a, b);
    }

    auto S = Digraph::Strongly_Connected_Components(D);

    cout << S.components.size() << endl;
    for (auto component: S.components) {
        cout << component.size();
        for (int v: component) {
            cout << " " << v;
        }

        cout << "\n";
    }
}
