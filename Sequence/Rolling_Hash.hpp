#pragma once

#include "../template/template.hpp"

namespace rolling_hash {
    template<typename F>
    class Rolling_Hash {
        const F base;
        int _size;
        vector<F> power;
        vector<F> hash;

        F hashing(const vector<F> &X) const {
            F res(0);
            for (F a: X) {
                res = base * res + a;
            }

            return res;
        }

        static vector<F> to_vector(const string &S) {
            vector<F> data(S.size());
            for (int i = 0; i < (int)S.size(); ++i) data[i] = F((unsigned char)S[i]);
            return data;
        }

        public:
        Rolling_Hash(const vector<F> &data, const F base): base(base), _size(data.size()) {
            power.resize(size() + 1);
            hash.resize(size() + 1);

            power[0] = F(1);
            hash[0] = F(0);
            for (int i = 0; i < size(); ++i) {
                power[i + 1] = base * power[i];
                hash[i + 1] = base * hash[i] + data[i];
            }
        }

        int size() const { return _size; }

        F get_base() const { return base; }

        /// @brief [0, p) におけるハッシュ値を求める
        /// @param p 右端 (p は含まれない)
        F get(const int p) const {
            return hash[p];
        }

        /// @brief [l, r) におけるハッシュ値を求める
        /// @param l 左端 (l は含まれる)
        /// @param r 右端 (r は含まれない)
        F get(const int l, const int r) const {
            return get(r) - power[r - l] * get(l);
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

        /// @brief 区間 [l0, r0) と [l1, r1) をこの順に連結したときのハッシュ値を求める
        F docking(const int l0, const int r0, const int l1, const int r1) const {
            return get(l0, r0) * power[r1 - l1] + get(l1, r1);
        }

        // 文字列用オーバーロード
        Rolling_Hash(const string &S, const F base): Rolling_Hash(to_vector(S), base) {}

        int count(const string &X, int start) const { return count(to_vector(X), start); }
        int count(const string &X) const { return count(to_vector(X), 0); }

        int find(const string &X, int start) const { return find(to_vector(X), start); }
        int find(const string &X) const { return find(to_vector(X), 0); }
    };

    // static な mod() と, 剰余を表すメンバ x を持つ型 (modint 想定)
    template<typename F>
    concept Modint_Like = requires(F f) {
        { F::mod() } -> convertible_to<int>;
        { f.x } -> convertible_to<uint64_t>;
    };

    /// @brief mod0, mod1 の 2 つの Rolling_Hash を組み合わせ, 衝突確率を下げたハッシュ.
    /// @tparam F0 1 つ目の mod に対応する modint 型 (Modint_Like を満たすこと)
    /// @tparam F1 2 つ目の mod に対応する modint 型 (Modint_Like を満たすこと)
    template<Modint_Like F0, Modint_Like F1>
    class Double_Rolling_Hash {
        public:
        /// @brief ハッシュ値の型 (F0 に対するハッシュ値と F1 に対するハッシュ値の組)
        using P = pair<F0, F1>;

        private:
        int _size;
        Rolling_Hash<F0> rh0;
        Rolling_Hash<F1> rh1;

        template<typename T>
        static vector<F0> to_vector0(const vector<T> &S) {
            vector<F0> data(S.size());
            for (int i = 0; i < (int)S.size(); ++i) data[i] = F0(S[i]);
            return data;
        }

        template<typename T>
        static vector<F1> to_vector1(const vector<T> &S) {
            vector<F1> data(S.size());
            for (int i = 0; i < (int)S.size(); ++i) data[i] = F1(S[i]);
            return data;
        }

        static vector<F0> to_vector0(const string &S) {
            vector<F0> data(S.size());
            for (int i = 0; i < (int)S.size(); ++i) data[i] = F0((unsigned char)S[i]);
            return data;
        }

        static vector<F1> to_vector1(const string &S) {
            vector<F1> data(S.size());
            for (int i = 0; i < (int)S.size(); ++i) data[i] = F1((unsigned char)S[i]);
            return data;
        }

        static P encode(const F0 &a0, const F1 &a1) {
            return P(a0, a1);
        }

        template<typename T>
        P hashing(const vector<T> &X) const {
            F0 a0 = Rolling_Hash<F0>(to_vector0(X), rh0.get_base()).get(0, X.size());
            F1 a1 = Rolling_Hash<F1>(to_vector1(X), rh1.get_base()).get(0, X.size());
            return encode(a0, a1);
        }

        P hashing(const string &X) const {
            F0 a0 = Rolling_Hash<F0>(to_vector0(X), rh0.get_base()).get(0, X.size());
            F1 a1 = Rolling_Hash<F1>(to_vector1(X), rh1.get_base()).get(0, X.size());
            return encode(a0, a1);
        }

        public:
        template<typename T>
        Double_Rolling_Hash(const vector<T> &data, const long long base):
            _size(data.size()), rh0(to_vector0(data), F0(base)), rh1(to_vector1(data), F1(base)) {}

        int size() const { return _size; }

        P get(const int p) const { return get(0, p); }

        /// @brief [l, r) におけるハッシュ値 (mod0, mod1 の混合値) を求める
        /// @param l 左端 (l は含まれる)
        /// @param r 右端 (r は含まれない)
        P get(const int l, const int r) const {
            return encode(rh0.get(l, r), rh1.get(l, r));
        }

        /// @brief 区間 [l0, r0) と [l1, r1) をこの順に連結したときのハッシュ値を求める
        P docking(const int l0, const int r0, const int l1, const int r1) const {
            return encode(rh0.docking(l0, r0, l1, r1), rh1.docking(l0, r0, l1, r1));
        }

        template<typename T>
        int count(const vector<T> &X, int start) const {
            P alpha = hashing(X);
            int res = 0;
            for (int i = start; i <= size() - (int)X.size(); ++i) {
                if (alpha == get(i, i + X.size())) res++;
            }

            return res;
        }

        template<typename T>
        int count(const vector<T> &X) const { return count(X, 0); }

        template<typename T>
        int find(const vector<T> &X, int start) const {
            P alpha = hashing(X);
            for (int i = start; i <= size() - (int)X.size(); ++i) {
                if (alpha == get(i, i + X.size())) return i;
            }

            return -1;
        }

        template<typename T>
        int find(const vector<T> &X) const { return find(X, 0); }

        template<typename T>
        int rfind(const vector<T> &X, int start) const {
            P alpha = hashing(X);
            for (int i = size() - (int)X.size(); i >= start; --i) {
                if (alpha == get(i, i + X.size())) return i;
            }

            return -1;
        }

        template<typename T>
        int rfind(const vector<T> &X) const { return rfind(X, 0); }

        template<typename T>
        int index(const vector<T> &X, int start) const {
            int i = find(X, start);
            assert(i != -1);
            return i;
        }

        template<typename T>
        int index(const vector<T> &X) const { return index(X, 0); }

        // 文字列用オーバーロード
        Double_Rolling_Hash(const string &S, const long long base):
            _size(S.size()), rh0(S, F0(base)), rh1(S, F1(base)) {}

        int count(const string &X, int start) const {
            P alpha = hashing(X);
            int res = 0;
            for (int i = start; i <= size() - (int)X.size(); ++i) {
                if (alpha == get(i, i + X.size())) res++;
            }

            return res;
        }

        int count(const string &X) const { return count(X, 0); }

        int find(const string &X, int start) const {
            P alpha = hashing(X);
            for (int i = start; i <= size() - (int)X.size(); ++i) {
                if (alpha == get(i, i + X.size())) return i;
            }

            return -1;
        }

        int find(const string &X) const { return find(X, 0); }

        int rfind(const string &X, int start) const {
            P alpha = hashing(X);
            for (int i = size() - (int)X.size(); i >= start; --i) {
                if (alpha == get(i, i + X.size())) return i;
            }

            return -1;
        }

        int rfind(const string &X) const { return rfind(X, 0); }

        int index(const string &X, int start) const {
            int i = find(X, start);
            assert(i != -1);
            return i;
        }

        int index(const string &X) const { return index(X, 0); }
    };
} // namespace rolling_hash
