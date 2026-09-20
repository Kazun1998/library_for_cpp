#pragma once

#include "../template/template.hpp"
#include "Rolling_Hash_Base.hpp"

namespace rolling_hash {
    /// @brief mod (2^61 - 1) 上で計算するローリングハッシュ
    class Rolling_Hash_Mersenne : public Rolling_Hash_Base<unsigned long long, Rolling_Hash_Mersenne> {
        using ull = unsigned long long;
        using Base = Rolling_Hash_Base<ull, Rolling_Hash_Mersenne>;
        friend Base;

        static constexpr ull Mod = 0x1fffffffffffffff;

        ull one() const { return 1; }
        ull zero() const { return 0; }

        ull mul(ull a, ull b) const {
            __uint128_t c = __uint128_t(a) * b;
            c = (c >> 61) + (c & Mod);
            if (c >= Mod) c -= Mod;
            return (ull)c;
        }

        ull add(ull a, ull b) const {
            ull c = a + b;
            if (c >= Mod) c -= Mod;
            return c;
        }

        ull sub(ull a, ull b) const {
            return (a >= b) ? (a - b) : (Mod - (b - a));
        }

        template<typename T>
        static vector<ull> to_vector(const vector<T> &X) {
            vector<ull> data(X.size());
            for (int i = 0; i < (int)X.size(); ++i) data[i] = (ull)X[i];
            return data;
        }

        static vector<ull> to_vector(const string &S) {
            vector<ull> data(S.size());
            for (int i = 0; i < (int)S.size(); ++i) data[i] = (ull)(unsigned char)S[i];
            return data;
        }

        public:
        using Base::count;
        using Base::find;
        using Base::rfind;

        template<typename T>
        Rolling_Hash_Mersenne(const vector<T> &X, const ull base): Base(base) { this->build(to_vector(X)); }

        template<typename T>
        int count(const vector<T> &X, int start) const { return count(to_vector(X), start); }
        template<typename T>
        int count(const vector<T> &X) const { return count(to_vector(X), 0); }

        template<typename T>
        int find(const vector<T> &X, int start) const { return find(to_vector(X), start); }
        template<typename T>
        int find(const vector<T> &X) const { return find(to_vector(X), 0); }

        template<typename T>
        int rfind(const vector<T> &X, int pos) const { return rfind(to_vector(X), pos); }
        template<typename T>
        int rfind(const vector<T> &X) const { return rfind(to_vector(X), size()); }

        // 文字列用オーバーロード
        Rolling_Hash_Mersenne(const string &S, const ull base): Rolling_Hash_Mersenne(to_vector(S), base) {}

        int count(const string &X, int start) const { return count(to_vector(X), start); }
        int count(const string &X) const { return count(to_vector(X), 0); }

        int find(const string &X, int start) const { return find(to_vector(X), start); }
        int find(const string &X) const { return find(to_vector(X), 0); }

        int rfind(const string &X, int pos) const { return rfind(to_vector(X), pos); }
        int rfind(const string &X) const { return rfind(to_vector(X), size()); }
    };
} // namespace rolling_hash
