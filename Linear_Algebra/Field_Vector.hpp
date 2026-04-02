#pragma once

#include "../template/template.hpp"
#include "Field_Matrix.hpp"

/**
 * @brief 体 F 上のベクトル空間の元（ベクトル）を表すクラス
 * @tparam F 体の要素の型（加減乗除が定義されており、F(0), F(1), .inverse() 等を持つこと）
 */
template<typename F>
class Field_Vector {
    private:
    vector<F> vec; ///< ベクトルの成分を格納する動的配列

    public:
    /** @brief デフォルトコンストラクタ */
    Field_Vector() = default;
    /** @brief std::vector からの変換コンストラクタ */
    Field_Vector(const vector<F> &_vec): vec(_vec) {};
    /** @brief 次元 n の零ベクトルを生成するコンストラクタ */
    Field_Vector(const int n): vec(vector<F>(n, F(0))) {};
    /** @brief 初期化リストからのコンストラクタ */
    Field_Vector(initializer_list<F> init) : vec(init) {}

    /**
     * @brief ベクトルの次元（要素数）を取得する
     * @return int 次元
     */
    inline int dimension () const { return vec.size(); }
    /** @brief dimension() のエイリアス */
    inline int size() const { return vec.size(); }

    /** @name イテレータ */
    ///@{
    inline typename vector<F>::iterator begin() { return vec.begin(); }
    inline typename vector<F>::iterator end() { return vec.end(); }
    inline typename vector<F>::const_iterator begin() const { return vec.begin(); }
    inline typename vector<F>::const_iterator end() const { return vec.end(); }
    ///@}

    /**
     * @brief 第 i 成分へのアクセス
     * @param i インデックス
     * @return const F& 成分
     */
    inline const F &operator[](int i) const { return vec[i]; }
    /**
     * @brief 第 i 成分への参照
     * @param i インデックス
     * @return F& 成分への参照
     */
    inline F &operator[](int i) { return vec[i]; }

    /** @name 比較演算子 */
    ///@{
    bool operator==(const Field_Vector &w) const { return vec == w.vec; }
    bool operator!=(const Field_Vector &w) const { return !((*this) == w); }
    ///@}

    /**
     * @brief 逆元（各成分を -1 倍したベクトル）を求める
     * @return Field_Vector 逆元
     */
    Field_Vector operator-() const {
        Field_Vector v(dimension ());
        for (int i = 0; i < dimension (); i++){
            v[i] = -(*this)[i];
        }
        return v;
    }

    /** @name 算術演算子 */
    ///@{
    /**
     * @brief ベクトル加法（破壊的）
     * @param w 加えるベクトル
     * @return Field_Vector& 自身の参照
     */
    Field_Vector& operator+=(const Field_Vector &w) {
        assert (dimension () == w.dimension ());
        for (int i = 0; i < dimension (); i++){ (*this)[i] += w[i]; }
        return *this;
    }
    /**
     * @brief ベクトル加法
     * @param w 加えるベクトル
     * @return Field_Vector 和
     */
    Field_Vector operator+(const Field_Vector &w) const { return Field_Vector(*this) += w; }

    /**
     * @brief ベクトル減法（破壊的）
     * @param w 引くベクトル
     * @return Field_Vector& 自身の参照
     */
    Field_Vector& operator-=(const Field_Vector &w) {
        assert (dimension () == w.dimension ());
        for (int i = 0; i < dimension (); i++){ (*this)[i] -= w[i]; }
        return *this;
    }
    /**
     * @brief ベクトル減法
     * @param w 引くベクトル
     * @return Field_Vector 差
     */
    Field_Vector operator-(const Field_Vector &w) const { return Field_Vector(*this) -= w; }
    ///@}

    /** @name スカラー演算 */
    ///@{
    /**
     * @brief スカラー倍（破壊的）
     * @param a 倍率
     * @return Field_Vector& 自身の参照
     */
    Field_Vector& operator*=(const F& a) {
        for (int i = 0; i < dimension (); i++){ (*this)[i] *= a; }
        return *this;
    }
    /**
     * @brief スカラー倍
     * @param a 倍率
     * @return Field_Vector スカラー倍後のベクトル
     */
    Field_Vector operator*(const F &a) const { return Field_Vector(*this) *= a; }

    /**
     * @brief スカラーによる除算（破壊的）
     * @param a 除数
     * @return Field_Vector& 自身の参照
     */
    Field_Vector& operator/=(const F& a) {
        const F a_inv = a.inverse(); // inverse()の結果をconstで保持
        for (int i = 0; i < dimension (); i++){ (*this)[i] *= a_inv; }
        return *this;
    }
    /**
     * @brief スカラーによる除算
     * @param a 除数
     * @return Field_Vector 除算後のベクトル
     */
    Field_Vector operator/(const F &a) const { return Field_Vector(*this) /= a; }
    ///@}

    /**
     * @brief 全ての成分が 0 かどうかを判定する
     * @return true 零ベクトルのとき
     * @return false それ以外のとき
     */
    bool is_zero() const {
        for (int i = 0; i < dimension (); i++) {
            if ((*this)[i] != F(0)) { return false; }
        }
        return true;
    }

    /**
     * @brief 入力ストリームからの読み込み
     */
    friend istream &operator>>(istream &is, Field_Vector &v) {
        for (int i = 0; i < v.dimension (); i++) { is >> v[i]; }
        return is;
    }

    /**
     * @brief 出力ストリームへの書き出し
     * @details 成分を空白区切りで出力する
     */
    friend ostream &operator<<(ostream &os, const Field_Vector &v) {
        for (int i = 0; i < v.dimension (); i++) {
            os << (i ? " ": "") << v[i];
        }
        return os;
    }

    /**
     * @brief 内積を計算する
     * @param w 相手のベクトル
     * @return F 内積の結果
     */
    F inner(const Field_Vector<F> &w) const {
        assert(dimension() == w.dimension());

        F res = F(0);
        for (int i = 0; i < dimension (); i++) { res += (*this)[i] * w[i]; }
        return res;
    }

    /**
     * @brief 単位ベクトルを生成する
     * @param n 次元
     * @param i 1 にするインデックス
     * @return Field_Vector 第 i 成分が 1 で、他が 0 のベクトル
     */
    static Field_Vector Unit(int n, int i) {
        Field_Vector v(n);
        if (i >= 0 && i < n) v[i] = F(1);
        return v;
    }
};

/**
 * @brief スカラー * ベクトル
 * @tparam F 体の型
 * @param a スカラー
 * @param v ベクトル
 * @return Field_Vector<F> 結果
 */
template<typename F>
Field_Vector<F> operator* (const F &a, const Field_Vector<F> &v) { return v * a; }

/**
 * @brief 二つのベクトルの内積を計算する便利関数
 * @tparam F 体の型
 * @param u ベクトル1
 * @param v ベクトル2
 * @return F 内積の結果
 */
template<typename F>
F inner(const Field_Vector<F> &u, const Field_Vector<F> &v) { return u.inner(v); }

/**
 * @brief 行列 A によるベクトル v の線形変換（作用） Ax を計算する
 * @param A 行列
 * @param v ベクトル
 * @return Field_Vector<F> 変換後のベクトル
 */
template<typename F>
Field_Vector<F> Action(const Field_Matrix<F> &A, const Field_Vector<F> &v) {
    assert(A.col == v.dimension());

    Field_Vector<F> res(A.row);
    for (int i = 0; i < A.row; i++) {
        for (int j = 0; j < A.col; j++) {
            res[i] += A[i, j] * v[j];
        }
    }

    return res;
}
