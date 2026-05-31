#include"../template/template.hpp"

/**
 * @brief 2-SAT (2-Satisfiability Problem) を強連結成分分解を用いて解くクラス.
 */
class Two_SAT {
    int N;
    int id_number;
    vector<int> id, order;
    vector<bool> used;

    inline int var_to_index(const int v) const { return max(2 * v, 2 * (-v - 1) + 1); }

    // 弧 X[i] => X[j] を追加する. ただし, X[~i] = not X[i] とする.
    void add_clause(int i, int j) {
        int p = var_to_index(i), q = var_to_index(j);
        arc[p].emplace_back(q);
        rev[q].emplace_back(p);
    }

    void dfs1(int v) {
        used[v] = true;
        for (int w : arc[v]) {
            unless(used[w]) { dfs1(w); }
        }
        order.emplace_back(v);
    }

    void dfs2(int v) {
        id[v] = id_number;
        for (auto w : rev[v]) {
            if (id[w] == -1) { dfs2(w); }
        }
    }

    public:
    vector<vector<int>> arc, rev;
    bool satisfiable;
    vector<bool> answer;

    Two_SAT(int N): N(N) {
        arc.resize(2 * N);
        rev.resize(2 * N);
    }

    int add_variable() {
        int id = N;
        arc.emplace_back(vector<int>()); arc.emplace_back(vector<int>());
        rev.emplace_back(vector<int>()); rev.emplace_back(vector<int>());
        N++;

        return id;
    }

    vector<int> add_variables(int k = 1) {
        vector<int> I;
        for (; k > 0; k--) { I.emplace_back(add_variable()); }
        return I;
    }

    /// @brief 現在の変数の数を返す.
    /// @return 変数の数
    inline int variable_number() { return N; }

    /// @brief 制約 (X_i = f) => (X_j = g) を追加する.
    /// @param i 変数 i
    /// @param f 変数 i の真偽
    /// @param j 変数 j
    /// @param g 変数 j の真偽
    void add_imply(int i, bool f, int j, int g) { add_imply(f ? i : ~i, g ? j : ~j); }

    /// @brief リテラル i => リテラル j という制約を追加する.
    /// @details ~i とすることでリテラルの否定を指定できる.
    /// @param i 始点となるリテラル
    /// @param j 終点となるリテラル
    void add_imply(int i, int j) {
        add_clause(i, j);
        add_clause(~j, ~i);
    }

    
    /// @brief (X_i = f) or (X_j = g) という制約を追加する.
    /// @param i 変数 i
    /// @param f 変数 i の真偽
    /// @param j 変数 j
    /// @param g 変数 j の真偽
    inline void add_or(int i, bool f, int j, bool g) { add_imply(i, !f, j, g); }

    /// @brief リテラル i or リテラル j という制約を追加する.
    /// @param i リテラル i
    /// @param j リテラル j
    inline void add_or(int i, int j) { add_imply(~i, j); }

    /// @brief not ((X_i = f) and (X_j = g)) という制約を追加する.
    /// @param i 変数 i
    /// @param f 変数 i の真偽
    /// @param j 変数 j
    /// @param g 変数 j の真偽
    inline void add_nand(int i, bool f, int j, bool g) { add_imply(i, f, j, !g); }

    /// @brief リテラル i nand リテラル j という制約を追加する.
    /// @param i リテラル i
    /// @param j リテラル j
    inline void add_nand(int i, int j) { add_imply(i, ~j); }

    /// @brief X_i = X_j という制約を追加する.
    /// @param i 変数 i
    /// @param j 変数 j
    inline void add_equal(int i, int j) { add_imply(i, j); add_imply(j, i); }

    /// @brief X_i != X_j という制約を追加する.
    /// @param i 変数 i
    /// @param j 変数 j
    inline void add_not_equal(int i, int j) { add_equal(i, ~j); }

    /// @brief X_i = True という制約を追加する.
    /// @param i 変数 i
    inline void set_true(int i) { add_clause(~i, i); }

    /// @brief X_i = False という制約を追加する.
    /// @param i 変数 i
    inline void set_false(int i) { add_clause(i, ~i); }

    /// @brief 2-SAT を解き、充足可能性を判定する.
    /// @details 強連結成分分解を用いて O(N + M) (M は制約数) で計算する.
    /// @return 充足可能であれば true, 不可能であれば false.
    bool solve() {
        order.clear();
        used.assign(2 * N, false);
        for (int i = 0; i < 2 * N; i++) {
            if (!used[i]) { dfs1(i); }
        }

        reverse(order.begin(), order.end());
        id.assign(2 * N, -1);

        id_number = 0;
        for (int v : order) {
            unless(id[v] == -1) { continue; }

            dfs2(v);
            id_number++;
        }

        answer.assign(N, false);
        for (int i = 0; i < N; i++) {
            if (id[2 * i] == id[2 * i + 1]) {
                answer.clear();
                return satisfiable = false;
            }

            answer[i] = (id[2 * i] > id[2 * i + 1]);
        }

        return satisfiable = true;
    }
};
