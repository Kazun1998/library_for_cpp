#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include"../../template/template.hpp"
#include"../../Algebra/Todd_Coxeter.hpp"

using TC = Todd_Coxeter;
using Word = TC::Word;
using Relation = TC::Relation;

Word power(int x, int n) { return Word(n, x); }

// 作用表が表示と整合しているかを検証する.
void check_consistency(const TC &M, int K, const vector<Relation> &R) {
    int n = M.order();

    // 単位元の番号は 0.
    assert(M.eval({}) == 0);

    // 作用表の値は範囲内で, 全ての元は単位元から到達できる.
    vector<bool> seen(n, false);
    seen[0] = true;
    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int c = Q.front(); Q.pop();
        for (int x = 0; x < K; ++x) {
            int d = M.act(c, x);
            assert(0 <= d && d < n);
            if (!seen[d]) { seen[d] = true; Q.push(d); }
        }
    }
    assert(count(seen.begin(), seen.end(), true) == n);

    // 全ての元に対して, 各関係式の両辺の作用先が一致する.
    for (int c = 0; c < n; ++c) {
        for (const auto &[l, r]: R) {
            int cl = c, cr = c;
            for (int x: l) { cl = M.act(cl, x); }
            for (int x: r) { cr = M.act(cr, x); }
            assert(cl == cr);
        }
    }

    // eval は act を繰り返したものと一致する.
    for (const auto &[l, r]: R) {
        assert(M.eval(l) == M.eval(r));
    }
}

void verify() {
    const int a = 0, b = 1;

    // 位数 3 の巡回群
    {
        vector<Relation> R = {{power(a, 3), {}}};
        TC M(1, R);
        assert(M.order() == 3);
        assert(M.eval(power(a, 3)) == M.eval({}));
        assert(M.eval(power(a, 2)) != M.eval({a}));
        check_consistency(M, 1, R);
    }

    // 群にならないモノイド <a | a^3 = a>
    {
        vector<Relation> R = {{power(a, 3), {a}}};
        TC M(1, R);
        assert(M.order() == 3);
        assert(M.eval(power(a, 3)) == M.eval({a}));
        assert(M.eval(power(a, 2)) != M.eval({a}));
        assert(M.eval({a}) != M.eval({}));
        check_consistency(M, 1, R);
    }

    // 自明なモノイド <a | a = e>
    {
        vector<Relation> R = {{{a}, {}}};
        TC M(1, R);
        assert(M.order() == 1);
        check_consistency(M, 1, R);
    }

    // 冪等な元が生成する可換モノイド
    {
        vector<Relation> R = {{power(a, 2), {a}}, {power(b, 2), {b}}, {{a, b}, {b, a}}};
        TC M(2, R);
        assert(M.order() == 4);
        assert(M.eval({a, b}) == M.eval({b, a}));
        assert(M.eval({a, b, a}) == M.eval({a, b}));
        check_consistency(M, 2, R);
    }

    // 零元 z を持つモノイド <a, z | a^2 = z, az = za = z^2 = z>
    {
        const int z = 1;
        vector<Relation> R = {{power(a, 2), {z}}, {{a, z}, {z}}, {{z, a}, {z}}, {{z, z}, {z}}};
        TC M(2, R);
        assert(M.order() == 3);
        assert(M.eval({a, a}) == M.eval({z}));
        assert(M.eval({a}) != M.eval({z}));
        check_consistency(M, 2, R);
    }

    // 対称群 S_3
    {
        vector<Relation> R = {{power(a, 2), {}}, {power(b, 2), {}}, {{a, b, a, b, a, b}, {}}};
        TC M(2, R);
        assert(M.order() == 6);
        assert(M.eval({a, b, a}) == M.eval({b, a, b}));
        assert(M.eval({a, b}) != M.eval({b, a}));
        check_consistency(M, 2, R);
    }

    // 交代群 A_4 = <a, b | a^2, b^3, (ab)^3>, 対称群 S_4 = <a, b | a^2, b^3, (ab)^4>
    {
        vector<Relation> R = {{power(a, 2), {}}, {power(b, 3), {}}, {{a, b, a, b, a, b}, {}}};
        TC M(2, R);
        assert(M.order() == 12);
        check_consistency(M, 2, R);

        R.back() = {{a, b, a, b, a, b, a, b}, {}};
        TC N(2, R);
        assert(N.order() == 24);
        check_consistency(N, 2, R);
    }

    // 四元数群 Q_8 = <a, b | a^4 = e, a^2 = b^2, b^{-1} a b = a^{-1}>
    // b^4 = a^4 = e なので b^{-1} = b^3, a^{-1} = a^3 として書く.
    {
        vector<Relation> R = {{power(a, 4), {}}, {power(a, 2), power(b, 2)}, {{b, b, b, a, b}, power(a, 3)}};
        TC M(2, R);
        assert(M.order() == 8);
        check_consistency(M, 2, R);
    }

    // Coxeter 生成元による対称群 S_n の位数は n!
    {
        ll fact = 1;
        for (int n = 2; n <= 6; ++n) {
            fact *= n;

            int K = n - 1;
            vector<Relation> R;
            for (int i = 0; i < K; ++i) { R.push_back({{i, i}, {}}); }
            for (int i = 0; i + 1 < K; ++i) { R.push_back({{i, i + 1, i}, {i + 1, i, i + 1}}); }
            for (int i = 0; i < K; ++i) {
                for (int j = i + 2; j < K; ++j) { R.push_back({{i, j}, {j, i}}); }
            }

            TC M(K, R);
            assert(M.order() == fact);
            check_consistency(M, K, R);
        }
    }
}

int main() {
    verify();
    cout << "Hello World" << endl;
}
