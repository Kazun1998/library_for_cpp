#include "../template/template.hpp"

/// @brief 尺取り法の一般化版. 閉区間 [l, r] を管理する add/remove/cond を渡すことで, 区間和以外の条件にも対応できる.
/// @tparam AddFunc void(int r) 型. 要素 r を区間に追加する.
/// @tparam RemoveFunc void(int i) 型. 要素 i を区間から除く.
/// @tparam CondFunc bool() 型. 現在保持している閉区間が条件を満たすかを返す.
/// @param n 数列の長さ.
/// @param add 要素を区間に追加する操作.
/// @param remove 要素を区間から除く操作.
/// @param cond 現在の区間が条件を満たすかどうかの判定 (add(r) 後に false なら remove(r) で取り消す).
/// @return result[l] := l を固定したとき, 閉区間 [l, result[l]] が条件を満たすような最大の result[l] (満たす index が存在しなければ l - 1).
template <class AddFunc, class RemoveFunc, class CondFunc>
vector<int> Two_Pointers(const int n, const AddFunc &add, const RemoveFunc &remove, const CondFunc &cond) {
    vector<int> result(n, -1);
    int r = 0;

    for (int l = 0; l < n; ++l) {
        if (r < l) r = l;

        while (r < n) {
            add(r);
            if (cond()) {
                ++r;
            } else {
                remove(r);
                break;
            }
        }

        result[l] = r - 1;

        if (l < r) {
            remove(l);
        }
    }

    return result;
}

/// @brief 尺取り法 (群版). data の要素が群 (単位元 e, 演算 op, 逆元 inv) をなす場合に, 区間の総積を自動で管理する.
/// @tparam G 群の元の型.
/// @tparam OpFunc G(G, G) 型. 群の演算. 結合的である必要がある.
/// @tparam InvFunc G(G) 型. 群の逆元. op(inv(x), x) = e を満たす必要がある.
/// @tparam CondFunc bool(G) 型. 区間の総積が条件を満たすかを返す.
/// @param data 数列.
/// @param e 単位元.
/// @param op 群の演算.
/// @param inv 群の逆元.
/// @param cond 総積 op(data[l], op(data[l + 1], ..., data[r])) が条件を満たすかどうかの判定.
/// @return result[l] := l を固定したとき, 閉区間 [l, result[l]] が条件を満たすような最大の result[l] (満たす index が存在しなければ l - 1).
template <class G, class OpFunc, class InvFunc, class CondFunc>
vector<int> Two_Pointers_Group(const vector<G> &data, const G &e, const OpFunc &op, const InvFunc &inv, const CondFunc &cond) {
    const int n = data.size();
    G prod = e;

    return Two_Pointers(
        n,
        [&](int i) { prod = op(prod, data[i]); },
        [&](int i) { prod = op(inv(data[i]), prod); },
        [&]() { return cond(prod); }
    );
}

/// @brief 尺取り法 (直接判定版). 閉区間 [l, r] が条件を満たすかどうかを cond(l, r) で直接判定できる場合に使う. 状態の管理 (add/remove) が不要.
/// @tparam CondFunc bool(int, int) 型. cond(l, r) は閉区間 [l, r] が条件を満たすかを返す. l を固定したとき r に関して単調 (r が条件を満たすなら l <= r' <= r を満たす r' も条件を満たす) である必要がある.
/// @param n 数列の長さ.
/// @param cond 閉区間 [l, r] が条件を満たすかどうかの判定.
/// @return result[l] := l を固定したとき, 閉区間 [l, result[l]] が条件を満たすような最大の result[l] (満たす index が存在しなければ l - 1).
template <class CondFunc>
vector<int> Two_Pointers_Direct(const int n, const CondFunc &cond) {
    vector<int> result(n, -1);
    int r = 0;

    for (int l = 0; l < n; ++l) {
        if (r < l) r = l;

        while (r < n && cond(l, r)) {
            ++r;
        }

        result[l] = r - 1;
    }

    return result;
}
