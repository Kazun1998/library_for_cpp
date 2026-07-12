#pragma once

#include"Field_Vector.hpp"

template<typename F>
class Field_Vector_Space {
    private:
    vector<int> index;
    vector<Field_Vector<F>> basis;
    int n;

    public:
    Field_Vector_Space(const int _n): n(_n) { basis.clear(); }
    Field_Vector_Space(const int _n, const vector<Field_Vector<F>> &vectors): n(_n) {
        for (Field_Vector<F> v: vectors) { add_vector(v); }
    }

    /**
     * @brief 零空間 {0} を生成する
     * @param n 全空間の次元
     * @return Field_Vector_Space 零空間を表すオブジェクト
     */
    static Field_Vector_Space Zero_Space(int n) {
        return Field_Vector_Space(n);
    }

    /**
     * @brief 全空間 F^n を生成する
     * @param n 次元
     * @return Field_Vector_Space 全空間を表すオブジェクト
     */
    static Field_Vector_Space Full_Space(int n) {
        Field_Vector_Space res(n);
        for (int i = 0; i < n; i++) {
            res.add_vector(Field_Vector<F>::Unit(n, i));
        }
        return res;
    }

    int dimension() const { return basis.size(); }

    bool add_vector(const Field_Vector<F> &v) {
        Field_Vector<F> w = projection(v);
        if (w.is_zero()) { return false; }

        int i = 0;
        for (; i < n; i++) { unless(w[i] == 0) { break; } }

        w *= w[i].inverse();
        for (int k = 0; k < basis.size(); k++) {
            basis[k] -= basis[k][i] * w;
        }

        index.emplace_back(i);
        basis.emplace_back(w);
        return true;
    }

    Field_Vector<F> projection(const Field_Vector<F> &v) const {
        Field_Vector<F> w = Field_Vector(v);
        for (int k = 0; k < dimension(); k++) {
            w -= w[index[k]] * basis[k];
        }

        return w;
    }

    /**
     * @brief ベクトル v がこの部分空間に含まれるか判定する
     * @param v 判定するベクトル
     * @return true 含まれるとき
     * @return false 含まれないとき
     */
    bool contains(const Field_Vector<F> &v) const {
        return projection(v).is_zero();
    }

    vector<Field_Vector<F>> get_basis() const { return basis; }

    /**
     * @brief 2つの部分空間の和空間 V + W を求める
     */
    Field_Vector_Space operator+(const Field_Vector_Space &other) const {
        assert(n == other.n);
        Field_Vector_Space res(*this);
        for (const auto &v : other.basis) {
            res.add_vector(v);
        }
        return res;
    }

    Field_Vector_Space& operator+=(const Field_Vector_Space &other) {
        assert(n == other.n);
        for (const auto &v : other.basis) {
            add_vector(v);
        }
        return *this;
    }

    /**
     * @brief 部分空間の包含関係 V \subseteq W を判定する
     */
    bool operator<=(const Field_Vector_Space &other) const {
        assert(n == other.n);
        for (const auto &v : basis) {
            unless(other.contains(v)) return false;
        }
        return true;
    }

    /**
     * @brief 部分空間の等価性を判定する
     */
    bool operator==(const Field_Vector_Space &other) const {
        return dimension() == other.dimension() && *this <= other;
    }
};
