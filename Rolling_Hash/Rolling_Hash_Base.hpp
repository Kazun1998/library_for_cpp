#pragma once

#include "../template/template.hpp"

namespace rolling_hash {
    /// @brief Rolling_Hash 系のクラスに共通する処理をまとめた基底クラス (CRTP)
    /// @tparam F ハッシュ値の型
    /// @tparam Derived 実際の演算 (one, zero, mul, add, sub) を提供する派生クラス
    template<typename F, typename Derived>
    class Rolling_Hash_Base {
        protected:
        F base;
        int _size;
        vector<F> power;
        vector<F> hash;

        const Derived& self() const { return static_cast<const Derived&>(*this); }

        /// @brief data から power, hash テーブルを構築する
        void build(const vector<F> &data) {
            _size = (int)data.size();

            power.assign(size() + 1, self().one());
            hash.assign(size() + 1, self().zero());

            for (int i = 0; i < size(); ++i) {
                power[i + 1] = self().mul(base, power[i]);
                hash[i + 1] = self().add(self().mul(base, hash[i]), data[i]);
            }
        }

        Rolling_Hash_Base(const F base): base(base) {}

        public:
        int size() const { return _size; }

        F get_base() const { return base; }

        /// @brief [0, p) におけるハッシュ値を求める
        /// @param p 右端 (p は含まれない)
        F get(const int p) const { return hash[p]; }

        /// @brief [l, r) におけるハッシュ値を求める
        /// @param l 左端 (l は含まれる)
        /// @param r 右端 (r は含まれない)
        F get(const int l, const int r) const {
            return self().sub(get(r), self().mul(power[r - l], get(l)));
        }

        /// @brief 区間 [l0, r0) と [l1, r1) をこの順に連結したときのハッシュ値を求める
        F docking(const int l0, const int r0, const int l1, const int r1) const {
            return self().add(self().mul(get(l0, r0), power[r1 - l1]), get(l1, r1));
        }

        /// @brief X 全体のハッシュ値を求める
        F hashing(const vector<F> &X) const {
            F res = self().zero();
            for (const F &a: X) {
                res = self().add(self().mul(base, res), a);
            }

            return res;
        }

        int count(const vector<F> &X, int start) const {
            F alpha = hashing(X);
            int res = 0;
            for (int i = start; i <= size() - (int)X.size(); ++i) {
                if (alpha == get(i, i + X.size())) res++;
            }

            return res;
        }

        int count(const vector<F> &X) const { return count(X, 0); }

        int find(const vector<F> &X, int start) const {
            F alpha = hashing(X);
            for (int i = start; i <= size() - (int)X.size(); ++i) {
                if (alpha == get(i, i + X.size())) return i;
            }

            return -1;
        }

        int find(const vector<F> &X) const { return find(X, 0); }

        /// @brief 開始位置が pos 以下であるような X の出現のうち, 最も右側にあるものの位置を求める (std::string::rfind と同じ仕様)
        int rfind(const vector<F> &X, int pos) const {
            F alpha = hashing(X);
            for (int i = min(pos, size() - (int)X.size()); i >= 0; --i) {
                if (alpha == get(i, i + X.size())) return i;
            }

            return -1;
        }

        int rfind(const vector<F> &X) const { return rfind(X, size()); }
    };
} // namespace rolling_hash
