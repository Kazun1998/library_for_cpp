#pragma

#include"../template/template.hpp"

class Permutation {
    private:
    vector<int> perm, ind;

    public:
    constexpr Permutation(const int n) {
        perm.resize(n);
        ind.resize(n);
        iota(perm.begin(), perm.end(), 0);
        iota(ind.begin(), ind.end(), 0);
    }

    constexpr Permutation(const vector<int> &vec) : perm(vec) {
        ind.resize(perm.size());
        for (int i = 0; i < perm.size(); ++i) {
            ind[perm[i]] = i;
        }
    }

    /// @brief n 要素の恒等置換を生成する.
    static constexpr Permutation identity(int n) {
        return Permutation(n);
    }

    /// @brief i 番目と j 番目を交換する.
    ///
    /// ※ i と j を交換ではない.
    constexpr void swap(int i, int j) {
        int u = perm[i];
        int v = perm[j];
        std::swap(perm[i], perm[j]);
        std::swap(ind[u], ind[v]);
    }

    /// @brief u と v を交換
    ///
    /// ※ u 番目と v 番目を交換ではない.
    constexpr void transposition(int u, int v) {
        swap(ind[u], ind[v]);
    }

    /// @brief 置換を循環置換の積に分解する.
    /// @return 
    vector<vector<int>> cycle_division() const {
        vector<vector<int>> cycles;
        vector<bool> used(perm.size(), false);
        for (int i = 0; i < (int)perm.size(); ++i) {
            if (used[i]) continue;
            vector<int> cycle;
            int cur = i;
            while (!used[cur]) {
                used[cur] = true;
                cycle.push_back(cur);
                cur = perm[cur];
            }
            cycles.push_back(cycle);
        }
        return cycles;
    }

    /// @brief 互換の最小回数を求める.
    /// @return 
    int minimum_transposition() const {
        return perm.size() - cycle_division().size();
    }

    /// @brief 転倒数を求める.
    /// @return 
    long long inversion() const {
        long long ans = 0;
        int n = perm.size();
        vector<int> bit(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int x = perm[i] + 1; x > 0; x -= x & -x) s += bit[x];
            ans += i - s;
            for (int x = perm[i] + 1; x <= n; x += x & -x) bit[x]++;
        }
        return ans;
    }

    /// @brief 置換の符号（偶置換なら 1、奇置換なら -1）を返す.
    int sign() const {
        return (minimum_transposition() & 1) ? -1 : 1;
    }

    constexpr Permutation operator*(const Permutation &rhs) const {
        int n = perm.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = perm[rhs.perm[i]];
        }
        return Permutation(res);
    }

    constexpr Permutation& operator*=(const Permutation &rhs) {
        *this = *this * rhs;
        return *this;
    }

    /// @brief 逆置換を求める.
    /// @return 
    constexpr Permutation inverse() const {
        return Permutation(ind);
    }
};

long long permutation_inversion(const Permutation &P, const Permutation &Q) {
    return (Q * P.inverse()).inversion();
}

template<typename T>
optional<long long> list_inversion(const vector<T> &A, const vector<T> &B) {
    assert(A.size() == B.size());

    int n = A.size();
    map<T, vector<int>> dic;

    for (int i = 0; i < n; i++) dic[A[i]].emplace_back(i);

    for (auto& [ignore, lis]: dic) reverse(lis.begin(), lis.end());

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        if (dic[B[i]].empty()) return nullopt;

        p[i] = dic[B[i]].back();
        dic[B[i]].pop_back();
    }

    return Permutation(p).inversion();
}
