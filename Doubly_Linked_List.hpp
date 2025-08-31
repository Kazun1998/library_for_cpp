#include"template/template.hpp"

class Doubly_Linked_List {
    private:
    vector<int> front, back;

    public:
    Doubly_Linked_List(int N): front(N, -1), back(N, -1) {}

    // x の前は存在するか ?
    inline bool has_front(int x) const { return front[x] != -1; }

    // x の後は存在するか ?
    inline bool has_back(int x) const { return back[x] != -1; }

    // x の直前の項 (存在しない場合は first の値が返ってくる)
    inline int previous(int x, int first = -1) const { return has_front(x) ? front[x] : first; }

    // x の直後の項 (存在しない場合は last の値が返ってくる)
    inline int next(int x, int last = -1) const {  return has_back(x) ? back[x] : last; }

    // x から前に伸びるリンクを削除する.
    void disconnect_front(int x) {
        unless(has_front(x)) { return; }

        int y = front[x];
        front[x] = -1;
        back[y] = -1;
    }

    // x から後ろに伸びるリンクを削除する.
    void disconnect_back(int x) {
        unless(has_back(x)) { return; }

        int y = back[x];
        back[x] = -1;
        front[y] = -1;
    }

    // x に接続するリンクを削除し, x の前後が存在するならば, それらを繋ぐ.
    void extract(int x) {
        int a = front[x], b = back[x];
        disconnect_front(x);
        disconnect_back(x);

        if (a >= 0 && b >= 0) { connect(a, b); }
    }

    // x から y へのリンクを生成する (すでにある x からのリンクと y へのリンクは削除される).
    void connect(int x, int y) {
        disconnect_back(x);
        disconnect_front(y);

        back[x] = y;
        front[y] = x;
    }

    // x の直前に y を挿入する.
    void insert_front(int x, int y) {
        int z = front[x];

        connect(y, x);
        unless(z == -1) { connect(z, y); }
    }

    // x の直後に y を挿入する.
    void insert_back(int x, int y) {
        int z = back[x];

        connect(x, y);
        unless(z == -1) { connect(y, z); }
    }

    // x が属する弱連結成分の先頭を求める.
    int head(int x) const {
        while (has_front(x)) { x = front[x]; }
        return x;
    }

    // x が属する弱連結成分の末尾を求める.
    int tail(int x) const {
        while (has_back(x)) { x = back[x]; }
        return x;
    }

    vector<int> enumerate(int x) const {
        x = head(x);
        vector<int> A{x};

        while (has_back(x)) {
            x = back[x];
            A.emplace_back(x);
        }

        return A;
    }
};
