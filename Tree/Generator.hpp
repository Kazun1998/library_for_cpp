#include"Tree.hpp"

Tree Generate_Tree(int N, vector<vector<int>> adjacent, int root, int offset = 0) {
    Tree T(N, offset);
    T.set_root(root);

    vector<bool> seen(N + offset, false); seen[root] = true;
    deque<int> Q{root};

    while(!Q.empty()) {
        int v = Q.back(); Q.pop_back();
        for (int w: adjacent[v]) {
            if (seen[w]) { continue; }

            seen[w] = true;
            T.set_child(v, w);
            Q.push_back(w);
        }
    }

    T.seal();
    return T;
}

Tree Generate_Tree(int N, vector<pair<int, int>> edges, int root, int offset = 0) {
    vector<vector<int>> adjacent(N + offset, vector<int>());
    for (auto &&[u, v]: edges) {
        adjacent[u].emplace_back(v);
        adjacent[v].emplace_back(u);
    }

    return Generate_Tree(N, adjacent, root, offset);
}
