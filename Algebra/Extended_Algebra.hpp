#pragma

#include"../template/template.hpp"

class IndeterminateOperationError : public std::runtime_error {
    public:
    IndeterminateOperationError(const std::string& msg): std::runtime_error(msg) {}
};

template<typename R>
struct Extended_Algebra {
    private:
    R val;
    signed char inf_flag; // 0: finite, 1: +inf, -1: -inf
    Extended_Algebra(R val, signed char inf_flag): val(val), inf_flag(inf_flag) {}

    public:
    Extended_Algebra(): val(R()), inf_flag(0) {}
    Extended_Algebra(R val): val(val), inf_flag(0) {}

    Extended_Algebra operator-() const { return Extended_Algebra(-val, -inf_flag); }

    static const Extended_Algebra inf;

    bool is_finite() const { return inf_flag == 0; }
    bool is_infinite() const { return !is_finite(); }

    bool is_positive(const bool zero = false) const {
        if(is_infinite()) { return inf_flag > 0; }

        return zero ? val >= R() : val > R();
    }

    bool is_negative(const bool zero = false) const {
        if(is_infinite()) { return inf_flag < 0; }

        return zero ? val <= R() : val < R();
    }

    bool is_positive_infinite() const { return inf_flag == 1; }
    bool is_negative_infinite() const { return inf_flag == -1; }

    inline bool is_zero() const { return inf_flag == 0 && val == R(); }

    Extended_Algebra& operator+=(const Extended_Algebra &rhs) {
        if (is_positive_infinite() && rhs.is_negative_infinite()) {
            throw IndeterminateOperationError("Extended_Algebra: Indeterminate form (inf + (-inf))");
        }
        if (is_negative_infinite() && rhs.is_positive_infinite()) {
            throw IndeterminateOperationError("Extended_Algebra: Indeterminate form ((-inf) + inf)");
        }

        if (is_finite() && rhs.is_finite()) { val += rhs.val; }
        else if (is_positive_infinite() || rhs.is_positive_infinite()) { inf_flag = 1; }
        else if (is_negative_infinite() || rhs.is_negative_infinite()) { inf_flag = -1; }

        return *this;
    }

    friend Extended_Algebra operator+(const Extended_Algebra &lhs, const Extended_Algebra &rhs) { return Extended_Algebra(lhs) += rhs; }

    Extended_Algebra& operator-=(const Extended_Algebra &rhs) {
        if (this->is_positive_infinite() && rhs.is_positive_infinite()) { 
            throw IndeterminateOperationError("Extended_Algebra: Indeterminate form (inf - inf)");
        }
        if (this->is_negative_infinite() && rhs.is_negative_infinite()) {
            throw IndeterminateOperationError("Extended_Algebra: Indeterminate form ((-inf) - (-inf))");
        }

        if (is_finite() && rhs.is_finite()) { val -= rhs.val; }
        else if (is_positive_infinite() || rhs.is_negative_infinite()) { inf_flag = 1; }
        else if (is_negative_infinite() || rhs.is_positive_infinite()) { inf_flag = -1; }

        return *this;
    }

    friend Extended_Algebra operator-(const Extended_Algebra &lhs, const Extended_Algebra &rhs) { return Extended_Algebra(lhs) -= rhs; }

    Extended_Algebra& operator*=(const Extended_Algebra &rhs) {
        if (is_zero() || rhs.is_zero()) {
            val = R();
            inf_flag = 0;
            return *this;
        }

        if (is_finite() && rhs.is_finite()) { val *= rhs.val; return *this; }

        if (is_positive() == rhs.is_positive()) { inf_flag = 1; }
        else { inf_flag = -1; }

        return *this;
    }

    friend Extended_Algebra operator*(const Extended_Algebra &lhs, const Extended_Algebra &rhs) { return Extended_Algebra(lhs) *= rhs; }

    Extended_Algebra& operator/=(const Extended_Algebra &rhs) {
        // 0-1. 未定義形: (± inf) / (± inf)
        if (this->is_infinite() && rhs.is_infinite()) {
            throw IndeterminateOperationError("Extended_Algebra: Indeterminate form (inf / inf)");
        }
        // 0-2. 未定義形: 0 / 0
        if (this->is_zero() && rhs.is_zero()) {
            throw IndeterminateOperationError("Extended_Algebra: Indeterminate form (0 / 0)");
        }

        // 1. ゼロ除算: finite (non-zero) / 0 -> ±inf
        if (rhs.is_zero()) {
            // 分母が 0 であるが, 0-2 を通り抜けているので, 分子が 0 にはなり得ない.
            inf_flag = (is_positive() == rhs.is_positive()) ? 1 : -1;
            val = R();
            return *this;
        }

        // 2. どちらも有限 (分母 != 0)
        if (is_finite() && rhs.is_finite()) { 
            // ゼロ除算は上記 1 で処理済み
            val /= rhs.val; 
            return *this;
        }

        // 3. 無限大を含む確定的な計算
        // inf / finite (non-zero) または finite (zero) / inf
        val = R(); // 結果は inf / 0

        if (this->is_infinite() && rhs.is_finite()) {
            // inf / finite -> 符号は乗算と同じ
            inf_flag = (is_positive() == rhs.is_positive()) ? 1 : -1;
        } else { // finite / inf -> 0 (既に is_zero()で処理されているべきだが安全のため)
            inf_flag = 0;
        }

        return *this;
    }

    // 非複合演算子
    friend Extended_Algebra operator/(const Extended_Algebra &lhs, const Extended_Algebra &rhs) {  return Extended_Algebra(lhs) /= rhs; }

    // 比較
    friend bool operator==(const Extended_Algebra &lhs, const Extended_Algebra &rhs) {
        if (lhs.inf_flag != rhs.inf_flag) { return false; }

        if (lhs.is_finite()) { return lhs.val == rhs.val; }

        return true;
    }

    friend bool operator<(const Extended_Algebra &lhs, const Extended_Algebra &rhs) {
        if (lhs.inf_flag != rhs.inf_flag) { return lhs.inf_flag < rhs.inf_flag; }

        if (lhs.is_finite()) { return lhs.val < rhs.val; }

        return false;
    }

    friend bool operator!=(const Extended_Algebra &lhs, const Extended_Algebra &rhs) {return !(lhs == rhs);}
    friend bool operator> (const Extended_Algebra &lhs, const Extended_Algebra &rhs) {return rhs < lhs;}
    friend bool operator<=(const Extended_Algebra &lhs, const Extended_Algebra &rhs) {return (lhs < rhs) || (lhs == rhs);}
    friend bool operator>=(const Extended_Algebra &lhs, const Extended_Algebra &rhs) {return (lhs > rhs) || (lhs == rhs);}

    // 出力
    friend ostream &operator<<(ostream &os, const Extended_Algebra &x) {
        if (x.is_positive_infinite()) { return os << "inf"; }
        if (x.is_negative_infinite()) { return os << "-inf"; }
        return os << x.val;
    }
};

template<typename R>
const Extended_Algebra<R> Extended_Algebra<R>::inf = Extended_Algebra<R>(R(), 1);
