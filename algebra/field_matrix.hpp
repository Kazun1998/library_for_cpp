#pragma once

class SingularMatrixError: private exception{
    const char* what() const throw() {
        return "非正則行列に関する操作を行いました.";
    }
};

template<typename F>
class Field_Matrix{
    private:
    vector<vector<F>> mat;

    public:
    int row, col;

    public:
    Field_Matrix(int row, int col): row(row), col(col){
        mat.assign(row, vector<F>(col, F()));
    }

    Field_Matrix(int row): Field_Matrix(row, row){}

    Field_Matrix(vector<vector<F>> &ele): Field_Matrix(ele.size(), ele[0].size()){
        for (int i = 0; i < row; i++){
            copy(ele[i].begin(), ele[i].end(), mat[i].begin());
        }
    }

    static Field_Matrix Zero_Matrix(int row, int col) { return Field_Matrix(row, col); }

    static Field_Matrix Identity_Matrix(int size) {
        Field_Matrix A(size);
        for (int i = 0; i < size; i++) { A[i][i] = 1; }
        return A;
    }

    // サイズ
    pair<int, int> size() { return make_pair(row, col); }

    // 正方行列?
    bool is_square() { return row == col; }

    // 要素
    inline const vector<F> &operator[](int i) const { return mat[i]; }
    inline vector<F> &operator[](int i) { return mat[i]; }

    // 比較
    bool operator==(const Field_Matrix &B) const {
        if (row != B.row || col != B.col){ return false; }

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if ((*this)[i] != B[i]) return false;
            }
        }
        return true;
    }

    bool operator!=(const Field_Matrix &B) const { return !((*this) == B); }

    // マイナス元
    Field_Matrix operator-() const {
        Field_Matrix A(row, col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++) A[i][j] = -(*this)[i][j];
        }
        return A;
    }

    // 加法
    Field_Matrix& operator+=(const Field_Matrix &B){
        assert (row == B.row && col == B.col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    Field_Matrix operator+(const Field_Matrix &B) const { return Field_Matrix(*this) += B; }

    // 減法
    Field_Matrix& operator-=(const Field_Matrix &B){
        assert (row == B.row && col == B.col);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    Field_Matrix operator-(const Field_Matrix &B) const  {return Field_Matrix(*this) -= B; }

    // 乗法
    Field_Matrix& operator*=(const Field_Matrix &B){
        assert (col == B.row);
        vector<vector<F>> C(row, vector<F>(B.col, F()));

        for (int i = 0; i < row; i++){
            for (int k = 0; k < col; k++){
                for (int j = 0; j < B.col; j++){
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }

        mat.swap(C); col = B.col;
        return *this;
    }

    Field_Matrix operator*(const Field_Matrix &B) const { return Field_Matrix(*this)*=B; }

    // スカラー倍
    friend Field_Matrix operator*(const F &scaler, const Field_Matrix &rhs){
        Field_Matrix res(rhs);
        for (int i = 0; i < rhs.row; i++){
            for (int j = 0; j < rhs.col; j++) { res[i][j] *= scaler; }
        }

        return res;
    }

    bool operator!=(const Field_Matrix &B) const {return !((*this) == B);}

    // 逆行列
    Field_Matrix inverse(){
        assert (is_square());
        int N = col;
        Field_Matrix A(*this), B(N,N);
        for (int i = 0; i < N; i++) B[i][i] = F(1);

        for (int j = 0; j < N; j++){
            if (A[j][j] == 0){
                int i = j + 1;
                for (; i < N; i++){
                    if (A[i][j] != 0) break;
                }

                if (i == N) { throw SingularMatrixError(); }

                swap(A[i], A[j]); swap(B[i], B[j]);
            }

            F a_inv = A[j][j].inverse();

            for (int k = 0; k < N; k++){
                A[j][k] *= a_inv;
                B[j][k] *= a_inv;
            }

            for (int i = 0; i < N; i++){
                if (i == j) { continue; }

                F c = A[i][j];
                for (int k = 0; k < N; k++){
                    A[i][k] -= A[j][k] * c;
                    B[i][k] -= B[j][k] * c;
                }
            }
        }

        return B;
    }

    bool is_regular(){
        assert (is_square());
        int N = row;

        vector<vector<F>> A(N, vector<F>(N));

        for (int i = 0; i < N; i++){
            copy(mat[i].begin(), mat[i].end(), A[i].begin());
        }

        for (int j = 0; j < N; j++){
            if (A[j][j] == 0){
                int i = j + 1;
                for (; i < N; i++){
                    if (A[i][j] != 0) break;
                }
                if (i == N) return false;
                swap(A[i], A[j]);
            }

            F a_inv = A[j][j].inverse();
            for (int i = j + 1; i < N; i++){
                F c = -a_inv * A[i][j];

               for (int k = 0; k < N; k++){ A[i][k] += c * A[j][k]; }
            }
        }

        return true;
    }

    // 転置
    Field_Matrix transpose(){
        Field_Matrix B(col, row);
        for (int i = 0; i < col; i++){
            for (int j = 0; j < row; j++) B[i][j] = (*this)[j][i];
        }
        return B;
    }

    //
    bool is_valid(){return (row > 0) && (col > 0);}

    // 入力
    friend istream &operator>>(istream &is, Field_Matrix &A) {
        for (int i = 0; i < A.row; i++){
            for (int j = 0; j < A.col; j++){
                cin >> A[i][j];
            }
        }
        return is;
    }

    // 出力
    friend ostream &operator<<(ostream &os, const Field_Matrix &A){
        for (int i = 0; i < A.row; i++){
            for (int j = 0; j < A.col; j++){
                cout << (j ? " ": "") << A[i][j];
            }
            if (i < A.row - 1) cout << "\n";
        }
        return os;
    }
};

template<typename F>
Field_Matrix<F> power(Field_Matrix<F> A, int64_t n){
    assert (A.is_square());

    if (n == 0) { return Field_Matrix<F>::Identity_Matrix(A.row); }
    if (n < 0) { return power(A.inverse(), -n); }

    if (n % 2 == 0){
        Field_Matrix<F> B = power(A, n / 2);
        return B * B;
    } else {
        Field_Matrix<F> B = power(A, (n - 1) / 2);
        return A * B * B;
    }
}
