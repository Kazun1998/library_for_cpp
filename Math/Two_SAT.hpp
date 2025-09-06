#include"../template/template.hpp"

class Two_SAT{
    public:
    vector<vector<int>> arc,rev;
    bool satisfiable;
    vector<bool> answer;

    private:
    int N;

    public:
    Two_SAT(int N): N(N) {
        arc.resize(2 * N);
        rev.resize(2 * N);
    }

    public:
    // 頂点を 1 個追加する.
    int add_variable() {
        int id = N;
        arc.emplace_back(vector<int>()); arc.emplace_back(vector<int>());
        rev.emplace_back(vector<int>()); rev.emplace_back(vector<int>());
        N++;

        return id;
    }

    // 頂点を k 個追加する.
    vector<int> add_variables(int k = 1) {
        vector<int> I;
        for (; k > 0; k--){ I.emplace_back(add_variable()); }
        return I;
    }

    public:
    inline int variable_number() { return N; }

    private:
    inline int var_to_index(const int v) const { return max(2 * v, 2 * (-v - 1) + 1); }

    private:
    // 弧 X[i] => X[j] を追加する.
    // ただし, X[~i] = not X[i] とする.
    void add_clause(int i, int j) {
        int p = var_to_index(i), q = var_to_index(j);
        arc[p].emplace_back(q);
        rev[q].emplace_back(p);
    }

    public:
    // 節 (X[i] = f) => (X[j] = g) を追加する.
    void add_imply(int i, bool f, int j, int g) { add_imply(f ? i: ~i, g ? j: ~j); }

    void add_imply(int i, int j) {
        add_clause(i, j);
        add_clause(~j, ~i);
    }

    public:
    // (X[i] = f) or (X[j] = g) を追加する.
    inline void add_or(int i, bool f, int j, bool g) { add_imply(i, !f, j, g); }
    inline void add_or(int i, int j) { add_imply(~i, j); }

    public:
    // not ((X[i] = f) and (X[j] = g)) を追加する.
    inline void add_nand(int i, bool f, int j, bool g) { add_imply(i, f, j, !g); }
    inline void add_nand(int i, int j) { add_imply(i, ~j); }

    public:
    // X[i] = X[j] を追加する.
    inline void add_equal(int i, int j) { add_imply(i, j); add_imply(j, i); }

    public:
    // X[i] != X[j] を追加する.
    inline void add_not_equal(int i, int j) { add_equal(i, ~j); }

    public:
    // X[i] = True とする.
    inline void set_true(int i) { add_clause(~i, i); }

    public:
    // X[i]=False とする.
    inline void set_false(int i) {add_clause(i, ~i); }

    // 以下, 2-SAT を解くための強連結成分分解に関するメソッドたち
    private:
    int id_number;
    vector<int> id;
    vector<int> order; vector<bool> used;

    public:
    bool solve() {
        order.clear();
        used.assign(2 * N, false);

        for (int i = 0; i < 2 * N; i++){
            if (!used[i]) { dfs1(i); }
        }

        reverse(order.begin(), order.end());
        id.assign(2 * N, -1);

        id_number = 0;
        for (int v: order){
            unless(id[v] == -1) { continue; }

            dfs2(v);
            id_number++;
        }

        answer.assign(N, false);
        for (int i = 0; i < N; i++){
            if (id[2 * i] == id[2 * i + 1]){
                answer.clear();
                return satisfiable=false;
            }

            answer[i] = (id[2 * i] > id[2 * i + 1]);
        }

        return satisfiable = true;
    }

    private:
    void dfs1(int v){
        used[v] = true;
        for (int w: arc[v]){
            unless (used[w]) { dfs1(w); }
        }
        order.emplace_back(v);
    }

    void dfs2(int v){
        id[v] = id_number;
        for (auto w: rev[v]){
            if (id[w] == -1) { dfs2(w); }
        }
    }
};
