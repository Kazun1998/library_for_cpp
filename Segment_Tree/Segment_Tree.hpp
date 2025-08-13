#pragma once

template<typename M>
class Segment_Tree{
    private:
    int n;
    vector<M> data;
    const function<M(M, M)> op;
    const M unit;

    public:
    Segment_Tree(int size, const function<M(M, M)> op, const M unit): n(), op(op), unit(unit) {
        int m = 1;
        while (m < size) { m *= 2; }

        n = m;
        data.assign(2 * n, unit);
    }

    Segment_Tree(const vector<M> &vec, const function<M(M, M)> op, const M unit): 
        Segment_Tree(vec.size(), op, unit) {
            for (int k = 0; k < n; k++) { data[k + n] = vec[k]; }
            for (int k = n - 1; k > 0; k--) { recalc(k); }
        }

    private:
    void recalc(int k) { data[k] = op(data[k << 1], data[k << 1 | 1]); }

    public:
    // 第 k 要素を x に更新する
    void update(int k, M x) {
        k += n;
        data[k] = x;

        for (k >>= 1; k; k >>= 1) { recalc(k); }
    }

    // 第 l 要素から第 r 要素までの総積を求める
    M product(int l, int r){
        l += n; r += n + 1;
        M vl = unit, vr = unit;
        while (l < r){
            if (l & 1){
                vl = op(vl, data[l]);
                l++;
            }

            if (r & 1){
                r--;
                vr = op(data[r], vr);
            }

            l >>= 1; r >>= 1;
        }

        return op(vl, vr);
    }
};
